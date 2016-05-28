//
//  TWTRDefines.h
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

#pragma once

#define TWC_STR_HELPER(x) #x
#define TWC_STR(x) TWC_STR_HELPER(x)

#define IS_UIKIT_AVAILABLE (TARGET_OS_IOS || TARGET_OS_TV)
#define IS_SOCIAL_ACCOUNTS_AVAILABLE (TARGET_OS_MAC && !TARGET_OS_WATCH && !TARGET_OS_TV)
