//
//  OSXApplication.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/25.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __MXE_OSXApplication_H__
#define __MXE_OSXApplication_H__

//
#import <Cocoa/Cocoa.h>

//
@interface OSXApplication : NSObject
{
}
+(OSXApplication*)	InstancePtr;

-(bool)	Initialize;
-(void)	Release;

@end

//
int		OSXApplicationMain(int argc, const char * argv[]);

//
#endif /* OSXApplication_H__ */
