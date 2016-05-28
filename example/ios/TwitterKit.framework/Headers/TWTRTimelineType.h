//
//  TWTRTimelineType.h
//  TwitterKit
//
//  Copyright (c) 2015 Twitter. All rights reserved.
//

/*
 *  Type of timelines that may be loaded and shown to the user.
 */
typedef NS_ENUM(NSUInteger, TWTRTimelineType) {
    
    /*
     *  User Timeline
     */
    TWTRTimelineTypeUser = 1,
    
    /*
     *  Search Timeline
     */
    TWTRTimelineTypeSearch,
    
    /**
     *  Collection Timeline
     */
    TWTRTimelineTypeCollection,
    
    /**
     *  List Timeline
     */
    TWTRTimelineTypeList,
};
