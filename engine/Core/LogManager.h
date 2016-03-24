#ifndef __MXE_LogManager_H__
#define __MXE_LogManager_H__

#pragma once

//
#include "Singleton.h"
#include "CoreBase.h"

// LogMessageLevel + LogContentLevel > MEX_LOG_THRESHOLD = message logged
#define MXE_LOG_THRESHOLD 4

//
enum LogContentLevel
{
	LCL_LOW			= 1,
	LCL_NORMAL		= 2,
	LCL_BOREME		= 3
};

//
enum LogMessageLevel
{
	LML_TRIVIAL		= 1,
	LML_NORMAL		= 2,
	LML_CRITICAL	= 3
};

//
class LogListener
{
public:
	LogListener( ){ }
    virtual ~LogListener() { }

public:
    virtual void message_logged( const StringT& message, LogMessageLevel lml, bool mask_debug, const StringT &log_name ) = 0;
};


//
class Log
{
public:
	Log( const StringT& name, bool debug_output = true, bool suppress_file_output = false);
	virtual ~Log();

protected:
	ofstreamT		m_fpLog;
	StringT			m_stringLogName;
	bool			m_bDebugOut;
	bool			m_bSuppressFile;
	bool			m_bTimeStamp;
	LogContentLevel	m_LogLevel;

protected:
	typedef std::vector<LogListener*> LogListenerArray;
	LogListenerArray m_Listeners;

public:
	/// Return the name of the log
	const StringT& GetName() const { return m_stringLogName; }
	/// Get whether debug output is enabled for this log
	bool IsDebugOutputEnabled() const { return m_bDebugOut; }
	/// Get whether file output is suppressed for this log
	bool IsFileOutputSuppressed() const { return m_bSuppressFile; }
	/// Get whether time stamps are printed for this log
	bool IsTimeStampEnabled() const { return m_bTimeStamp; }
	/// Enable or disable outputting log messages to the debugger.
	void SetDebugOutputEnabled(bool debugOutput);
	/// Sets the level of the log detail.
	void SetLogDetail(LogContentLevel lcl);
	/// Enable or disable time stamps.
	void SetTimeStampEnabled(bool timeStamp);
	/// Gets the level of the log detail.
	LogContentLevel GetLogDetail() const { return m_LogLevel; }
	/// Register a listener to this log
	void AddListener(LogListener* listener);
	/// Unregister a listener from this log
	void RemoveListener(LogListener* listener);

public:
	void LogMessage( const StringT& message, LogMessageLevel lml = LML_NORMAL, bool mask_debug = false );
};


//
class LogManager : public SingletonT<LogManager>, public CoreInstance
{
public:
	LogManager(void);
	virtual ~LogManager(void);

	virtual bool	Initialize();
	virtual void	Release();

	Log*			CreateLog(const StringT& filename, bool default_log = false, bool debugger_output = true, bool suppress_file_output = false);
	void			DestroyLog(const StringT& name);
	void			DestroyLog(Log* log);

	Log*			GetLog(const StringT& name);
	Log*			GetDefaultLog();
	Log*			SetDefaultLog(Log* log);
	void			SetLogDetail(LogContentLevel lcl);

	void			LogMessage( const StringT& message, LogMessageLevel lml = LML_NORMAL, bool mask_debug = false);
	void			LogMessage( LogMessageLevel lml, const StringT& message, bool mask_debug = false) 
	{ this->LogMessage(message, lml, mask_debug); }

protected:
	typedef std::map<StringT, Log*>		LogList;

	/// A list of all the logs the manager can access
	LogList		m_Logs;

	/// The default log to which output is done
	Log*		m_pDefaultLog;
};


//
#endif /* __MXE_LogManager_H__ */