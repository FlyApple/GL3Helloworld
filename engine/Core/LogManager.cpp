
#include "Precompile.h"
#include "LogManager.h"

//
Log::Log( const StringT& name, bool debugger_output, bool suppress_file_output )
		:	m_LogLevel(LCL_NORMAL), 
			m_bDebugOut(debugger_output),
			m_bSuppressFile(suppress_file_output), 
			m_bTimeStamp(true),
			m_stringLogName(name)
{
	// 是否创建日志文件:
	if (!m_bSuppressFile)
	{
		m_fpLog.open(name.c_str());
	}
}

Log::~Log( )
{
	if (!m_bSuppressFile)
	{ m_fpLog.close(); }
}

void	Log::LogMessage( const StringT& message, LogMessageLevel lml, bool mask_debug )
{
	if ( (m_LogLevel + lml) >= MXE_LOG_THRESHOLD )
	{
		//
		for( LogListenerArray::iterator i = m_Listeners.begin(); i != m_Listeners.end(); ++i )
		{ (*i)->message_logged( message, lml, mask_debug, m_stringLogName ); }

		//
		if (m_bDebugOut && !mask_debug)
		{ std::cerrT << message << std::endlT; }

		// Write time into log
		if (!m_bSuppressFile)
		{
			if (m_bTimeStamp)
			{
				tm		tmTime	= {0};
				time_t	ctTime; time(&ctTime);

				tm*		pTime	= &tmTime;
				localtime_s( &tmTime, &ctTime );

				m_fpLog << std::setw(2) << std::setfill(_T('0')) << pTime->tm_hour
					<< _T(":") << std::setw(2) << std::setfill(_T('0')) << pTime->tm_min
					<< _T(":") << std::setw(2) << std::setfill(_T('0')) << pTime->tm_sec
					<< _T(": ");
			}
			m_fpLog << message << std::endlT;

			// Flush stcmdream to ensure it is written (incase of a crash, we need log to be up to date)
			m_fpLog.flush();
		}
	}
}

void	Log::SetTimeStampEnabled(bool timeStamp)
{
	m_bTimeStamp = timeStamp;
}
void	Log::SetDebugOutputEnabled(bool debugOutput)
{
	m_bDebugOut = debugOutput;
}
void	Log::SetLogDetail(LogContentLevel lcl)
{
	m_LogLevel = lcl;
}
void	Log::AddListener(LogListener* listener)
{
	m_Listeners.push_back(listener);
}
void	Log::RemoveListener(LogListener* listener)
{
	m_Listeners.erase(std::find(m_Listeners.begin(), m_Listeners.end(), listener));
}


//
SINGLETON_IMPLE(LogManager);
LogManager::LogManager(void)
{
	m_pDefaultLog	= NULL;
}

LogManager::~LogManager(void)
{
}


void	LogManager::Release()
{
	for (LogList::iterator i = m_Logs.begin(); i != m_Logs.end(); ++i)
	{
		MXE_DELETE_POINTER( i->second );
	}
}

bool	LogManager::Initialize()
{
#if defined(_PLATFORM_WINDOW_)
#ifdef	_UNICODE
	std::coutT.imbue(std::locale(MXE_STREAM_LOCALE_CHS));
	std::cerrT.imbue(std::locale(MXE_STREAM_LOCALE_CHS));
#endif
#endif

	//
	return true;
}

Log*	LogManager::CreateLog(const StringT& filename, bool default_log, bool debugger_output, bool suppress_file_output)
{
	Log* log = new Log(filename, debugger_output, suppress_file_output);

	if( !m_pDefaultLog || default_log )
	{ m_pDefaultLog = log; }

	m_Logs.insert( LogList::value_type( StringToLower(filename), log ) );
	return log;
}

void	LogManager::DestroyLog(Log* log)
{
	this->DestroyLog(log->GetName());
}

void	LogManager::DestroyLog(const StringT& name)
{
	LogList::iterator i = m_Logs.find(StringToLower(name));
	if (i != m_Logs.end())
	{
		if (m_pDefaultLog == i->second)
		{ m_pDefaultLog = NULL; }

		MXE_DELETE_POINTER(i->second);

		m_Logs.erase(i);
	}

	// Set another default log if this one removed
	if (!m_pDefaultLog && !m_Logs.empty())
	{
		m_pDefaultLog = m_Logs.begin()->second;
	}
}

Log*	LogManager::GetDefaultLog()
{
	return m_pDefaultLog;
}

Log*	LogManager::SetDefaultLog(Log* log)
{
	Log* oldLog = m_pDefaultLog;

	m_pDefaultLog = log;

	return oldLog;
}

Log*	LogManager::GetLog( const StringT& name)
{
	LogList::iterator i = m_Logs.find(StringToLower(name));
	if (i != m_Logs.end())
	{ return i->second; }
	
	return NULL;
}

void	LogManager::SetLogDetail(LogContentLevel lcl)
{
	if (m_pDefaultLog)
	{
		m_pDefaultLog->SetLogDetail(lcl);
	}
}

void	LogManager::LogMessage( const StringT& message, LogMessageLevel lml, bool mask_debug)
{
	if (m_pDefaultLog)
	{
		m_pDefaultLog->LogMessage(message, lml, mask_debug);
	}	
}