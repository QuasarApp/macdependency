//
//  MyDocument.h
//  MacDependency
//
//  Created by Konrad Windszus on 19.06.09.
//  Copyright Konrad Windszus 2009 . All rights reserved.
//


#import <Cocoa/Cocoa.h>
#import "MachO/macho.h"
#import "MachO/machocache.h"
#import "MachOModel.h"
#import "PrioritySplitViewDelegate.h"
#import "SymbolTableController.h"
@interface MyDocument : NSDocument
{
	MachOCache* cache;
	MachO* machO;
	NSArray* contents;
	NSMutableAttributedString* log;
	PrioritySplitViewDelegate* splitViewDelegate;
	IBOutlet NSTreeController* dependenciesController;
	IBOutlet NSTextField* textFieldFilename;
	IBOutlet NSTextField* textFieldBottomBar;
	IBOutlet NSSplitView* mainSplitView;
	IBOutlet SymbolTableController* symbolTableController;
	unsigned int numDependencies;
}
- (NSAttributedString*)log;
- (void)setLog:(NSMutableAttributedString *)newLog;
- (void)appendLogLine:(NSString *)line withModel:(MachOModel*)model state:(State)state;
- (void)clearLog;

- (void)incrementNumDependencies;
- (void)resetNumDependencies;

- (MachOCache*)cache;

- (NSArray*)architectures;
- (IBAction)clickRevealInFinder:(id)sender;
- (NSString*)dependencyStatus;
- (SymbolTableController*)symbolTableController;
@end