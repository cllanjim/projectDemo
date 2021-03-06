//
//  ZFWaveChart.h
//  ZFChartView
//
//  Created by apple on 16/3/26.
//  Copyright © 2016年 apple. All rights reserved.
//

#import "ZFGenericChart.h"
#import "ZFConst.h"
#import "ZFPopoverLabel.h"
#import "ZFWave.h"
@class ZFWaveChart;

/*********************  ZFWaveChartDelegate(ZFWaveChart协议方法)  *********************/
@protocol ZFWaveChartDelegate <NSObject>

@optional

/**
 *  组宽(若不设置，默认为25.f)
 */
- (CGFloat)groupWidthInWaveChart:(ZFWaveChart *)waveChart;

/**
 *  组与组之间的间距(若不设置，默认为20.f)
 */
- (CGFloat)paddingForGroupsInWaveChart:(ZFWaveChart *)waveChart;

/**
 *  path颜色(若不设置，默认为ZFSkyBlue)
 *
 *  @return 返回UIColor
 */
- (UIColor *)pathColorInWaveChart:(ZFWaveChart *)waveChart;

/**
 *  用于编写x轴valueLabel点击后需要执行后续代码
 *
 *  @param index     点击的x轴valueLabel的位置下标
 */
- (void)waveChart:(ZFWaveChart *)waveChart popoverLabelAtIndex:(NSInteger)index;

@end


@interface ZFWaveChart : ZFGenericChart

@property (nonatomic, weak) id<ZFWaveChartDelegate> delegate;

/** 图表上value位置(默认为kChartValuePositionDefalut) */
@property (nonatomic, assign) kChartValuePosition valuePosition;
/** value文本颜色(默认黑色) */
@property (nonatomic, strong) UIColor * valueTextColor;
/** 超过y轴显示最大值时valueText颜色(默认为红色) */
@property (nonatomic, strong) UIColor * overMaxValueTextColor;
/** 波浪样式(默认为kWavePatternTypeForCurve) */
@property (nonatomic, assign) kWavePatternType wavePatternType;
/** valueLabel到波浪线的距离(默认为0.f) */
@property (nonatomic, assign) CGFloat valueLabelToWaveLinePadding;

#pragma mark - public method

/**
 *  重绘(每次更新数据后都需要再调一次此方法)
 */
- (void)strokePath;

@end
