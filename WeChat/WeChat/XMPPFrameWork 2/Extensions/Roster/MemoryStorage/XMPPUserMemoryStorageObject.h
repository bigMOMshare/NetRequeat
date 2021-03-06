#import <Foundation/Foundation.h>
#import "XMPPUser.h"
#import "XMPP.h"

#if TARGET_OS_IPHONE
    #import <UIKit/UIKit.h>
#else
    #import <Cocoa/Cocoa.h>
#endif

@class XMPPResourceMemoryStorageObject;


@interface XMPPUserMemoryStorageObject : NSObject <XMPPUser, NSCopying, NSSecureCoding>
{
	XMPPJID *jid;
	NSMutableDictionary *itemAttributes;
	NSMutableArray *groups;
	
	NSMutableDictionary *resources;
	XMPPResourceMemoryStorageObject *primaryResource;
	
#if TARGET_OS_IPHONE
	UIImage *photo;
#else
	NSImage *photo;
#endif
}

/*	From the XMPPUser protocol
	
- (XMPPJID *)jid;
- (NSString *)nickname;

- (BOOL)isOnline;
- (BOOL)isPendingApproval;

- (id <XMPPResource>)primaryResource;
- (id <XMPPResource>)resourceForJID:(XMPPJID *)jid;

- (NSArray *)allResources;

*/

- (NSString *)subscription;

- (NSString *)ask;

/**
 * Simple convenience method.
 * If a nickname exists for the user, the nickname is returned.
 * Otherwise the jid is returned (as a string).
**/
- (NSString *)displayName;

/**
 * An array of Group Names.
**/
- (NSArray *)groups;

/**
 * If XMPPvCardAvatarModule is included in the framework, the XMPPRoster will automatically integrate with it,
 * and we'll save the the user photos after they've been downloaded.
**/
#if TARGET_OS_IPHONE
@property (nonatomic, strong, readonly) UIImage *photo;
#else
@property (nonatomic, strong, readonly) NSImage *photo;
#endif

/**
 * Simple comparison methods.
**/

- (NSComparisonResult)compareByName:(XMPPUserMemoryStorageObject *)another;
- (NSComparisonResult)compareByName:(XMPPUserMemoryStorageObject *)another options:(NSStringCompareOptions)mask;

- (NSComparisonResult)compareByAvailabilityName:(XMPPUserMemoryStorageObject *)another;
- (NSComparisonResult)compareByAvailabilityName:(XMPPUserMemoryStorageObject *)another
                                        options:(NSStringCompareOptions)mask;

@end
