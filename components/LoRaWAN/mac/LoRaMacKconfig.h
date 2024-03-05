#ifndef LORAMACKCONFIG_H
#define LORAMACKCONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*******************
 * REGION
 *******************/
#ifdef CONFIG_REGION_EU868
    #define REGION_EU868
#endif
#ifdef CONFIG_REGION_US915
    #define REGION_US915
#endif
#ifdef CONFIG_REGION_CN779
    #define REGION_CN779
#endif
#ifdef CONFIG_REGION_EU433
    #define REGION_EU433
#endif
#ifdef CONFIG_REGION_AU915
    #define REGION_AU915
#endif
#ifdef CONFIG_REGION_AS923
    #define REGION_AS923
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_1
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_1
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_2
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_2
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_3
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_3
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_4
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_4
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_1_JP_CH24_CH38_LBT
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_1_JP_CH24_CH38_LBT
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_1_JP_CH24_CH38_DC
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_1_JP_CH24_CH38_DC
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_GROUP_AS923_1_JP_CH37_CH61_LBT_DC
        #define REGION_AS923_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_GROUP_AS923_1_JP_CH37_CH61_LBT_DC
    #endif
#endif
#ifdef CONFIG_REGION_CN470
    #define REGION_CN470

    #ifdef CONFIG_CHANNEL_PLAN_20MHZ_TYPE_A
        #define REGION_CN470_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_20MHZ_TYPE_A
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_20MHZ_TYPE_B
        #define REGION_CN470_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_20MHZ_TYPE_B
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_26MHZ_TYPE_A
        #define REGION_CN470_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_26MHZ_TYPE_A
    #endif
    #ifdef CONFIG_CHANNEL_PLAN_26MHZ_TYPE_B
        #define REGION_CN470_DEFAULT_CHANNEL_PLAN  CHANNEL_PLAN_26MHZ_TYPE_B
    #endif
#endif
#ifdef CONFIG_REGION_KR920
    #define REGION_KR920
#endif
#ifdef CONFIG_REGION_IN865
    #define REGION_IN865
#endif
#ifdef CONFIG_REGION_RU864
    #define REGION_RU864
#endif

#define SOFT_SE 


#ifdef CONFIG_USE_LRWAN_1_1_X_CRYPTO
    #define USE_LRWAN_1_1_X_CRYPTO  1
#else
    #define USE_LRWAN_1_1_X_CRYPTO  0
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LORAMACKCONFIG_H*/
