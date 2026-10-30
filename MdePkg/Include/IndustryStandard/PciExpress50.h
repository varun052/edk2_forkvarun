/** @file
Support for the PCI Express 5.0 standard.

This header file may not define all structures.  Please extend as required.

Copyright (c) 2020 - 2026, American Megatrends International LLC. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#pragma once

#include <IndustryStandard/PciExpress40.h>

#pragma pack(1)

/// The Physical Layer PCI Express Extended Capability definitions.
///
/// Based on section 7.7.6 of PCI Express Base Specification 5.0.
///@{
#define PCI_EXPRESS_EXTENDED_CAPABILITY_PHYSICAL_LAYER_32_0_ID    0x002A
#define PCI_EXPRESS_EXTENDED_CAPABILITY_PHYSICAL_LAYER_32_0_VER1  0x1

// Register offsets from Physical Layer PCI-E Ext Cap Header
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CAPABILITIES_OFFSET               0x04
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CONTROL_OFFSET                    0x08
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_STATUS_OFFSET                     0x0C
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA1_OFFSET     0x10
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA2_OFFSET     0x14
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA1_OFFSET    0x18
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA2_OFFSET    0x1C
#define PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_LANE_EQUALIZATION_CONTROL_OFFSET  0x20

typedef union {
  struct {
    UINT32    EqualizationByPassToHighestRateSupport : 1;               // bit 0
    UINT32    NoEqualizationNeededSupport            : 1;               // bit 1
    UINT32    Reserved1                              : 6;               // Reserved bit 2:7
    UINT32    ModifiedTSUsageMode0Support            : 1;               // bit 8
    UINT32    ModifiedTSUsageMode1Support            : 1;               // bit 9
    UINT32    ModifiedTSUsageMode2Support            : 1;               // bit 10
    UINT32    ModifiedTSReservedUsageModes           : 5;               // bit 11:15
    UINT32    Reserved2                              : 16;              // Reserved bit 16:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CAPABILITIES;

typedef union {
  struct {
    UINT32    EqualizationByPassToHighestRateDisable : 1;               // bit 0
    UINT32    NoEqualizationNeededDisable            : 1;               // bit 1
    UINT32    Reserved1                              : 6;               // Reserved bit 2:7
    UINT32    ModifiedTSUsageModeSelected            : 3;               // bit 8:10
    UINT32    Reserved2                              : 21;              // Reserved bit 11:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CONTROL;

typedef union {
  struct {
    UINT32    EqualizationComplete      : 1;  // bit 0
    UINT32    EqualizationPhase1Success : 1;  // bit 1
    UINT32    EqualizationPhase2Success : 1;  // bit 2
    UINT32    EqualizationPhase3Success : 1;  // bit 3
    UINT32    LinkEqualizationRequest   : 1;  // bit 4
    UINT32    ModifiedTSRcvd            : 1;  // bit 5
    UINT32    RcvdEnhancedLinkControl   : 2;  // bit 6:7
    UINT32    TransmitterPrecodingOn    : 1;  // bit 8
    UINT32    TransmitterPrecodeRequest : 1;  // bit 9
    UINT32    NoEqualizationNeededRcvd  : 1;  // bit 10
    UINT32    Reserved                  : 21; // Reserved bit 11:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_STATUS;

typedef union {
  struct {
    UINT32    RcvdModifiedTSUsageMode  : 3;  // bit 0:2
    UINT32    RcvdModifiedTSUsageInfo1 : 13; // bit 3:15
    UINT32    RcvdModifiedTSVendorId   : 16; // bit 16:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA1;

typedef union {
  struct {
    UINT32    RcvdModifiedTSUsageInfo2     : 24; // bit 0:23
    UINT32    AltProtocolNegotiationStatus : 2;  // bit 24:25
    UINT32    Reserved                     : 6;  // Reserved bit 26:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA2;

typedef union {
  struct {
    UINT32    TransModifiedTSUsageMode  : 3;  // bit 0:2
    UINT32    TransModifiedTSUsageInfo1 : 13; // bit 3:15
    UINT32    TransModifiedTSVendorId   : 16; // bit 16:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA1;

typedef union {
  struct {
    UINT32    TransModifiedTSUsageInfo2    : 24; // bit 0:23
    UINT32    AltProtocolNegotiationStatus : 2;  // bit 24:25
    UINT32    Reserved                     : 6;  // Reserved bit 26:31
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA2;

typedef union {
  struct {
    UINT8    DownstreamPortTransmitterPreset : 4; // bit 0..3
    UINT8    UpstreamPortTransmitterPreset   : 4; // bit 4..7
  } Bits;
  UINT8    Uint8;
} PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_LANE_EQUALIZATION_CONTROL;

typedef struct {
  PCI_EXPRESS_EXTENDED_CAPABILITIES_HEADER                         Header;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CAPABILITIES                 Capablities;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_CONTROL                      Control;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_STATUS                       Status;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA1       RcvdModifiedTs1Data;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_RCVD_MODIFIED_TS_DATA2       RcvdModifiedTs2Data;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA1      TransModifiedTs1Data;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_TRANS_MODIFIED_TS_DATA2      TransModifiedTs2Data;
  PCI_EXPRESS_REG_PHYSICAL_LAYER_32_0_LANE_EQUALIZATION_CONTROL    LaneEqualizationControl[1];
} PCI_EXPRESS_EXTENDED_CAPABILITIES_PHYSICAL_LAYER_32_0;
///@}

/// Alternate Protocol Negotiation Extended Capability Structure
///
/// Based on section 7.9.21 of PCI Express Base Specification 5.0
///@{
#define PCI_EXPRESS_EXTENDED_CAPABILITY_ALTERNATE_PROTOCOL_ID    0x002B
#define PCI_EXPRESS_EXTENDED_CAPABILITY_ALTERNATE_PROTOCOL_VER1  0x1

typedef struct {
  PCI_EXPRESS_EXTENDED_CAPABILITIES_HEADER    Header;
  UINT32                                      AltProtocolCapability;
  UINT32                                      AltProtocolStatus;
  UINT32                                      AltProtocolControl;
} PCI_EXPRESS_EXTENDED_CAPABILITIES_ALTERNATE_PROTOCOL;
///@}

/// Flattening Portal Bridge (FPB) Capability definitions.
///
/// Based on section 7.8.10 of PCI Express Base Specification 5.0.
///@{

///
/// FPB Capability ID
///
#define PCI_EXPRESS_CAPABILITY_ID_FPB  0x15

///
/// FPB Capability Register Offsets
///
#define PCI_EXPRESS_CAPABILITY_FPB_CAP_HEADER_OFFSET             0x00
#define PCI_EXPRESS_CAPABILITY_FPB_CAPABILITIES_OFFSET           0x04
#define PCI_EXPRESS_CAPABILITY_FPB_RID_VECTOR_CTRL1_OFFSET       0x08
#define PCI_EXPRESS_CAPABILITY_FPB_RID_VECTOR_CTRL2_OFFSET       0x0C
#define PCI_EXPRESS_CAPABILITY_FPB_MEM_LOW_VECTOR_CTRL_OFFSET    0x10
#define PCI_EXPRESS_CAPABILITY_FPB_MEM_HIGH_VECTOR_CTRL1_OFFSET  0x14
#define PCI_EXPRESS_CAPABILITY_FPB_MEM_HIGH_VECTOR_CTRL2_OFFSET  0x18
#define PCI_EXPRESS_CAPABILITY_FPB_VECTOR_ACCESS_CTRL_OFFSET     0x1C
#define PCI_EXPRESS_CAPABILITY_FPB_VECTOR_ACCESS_DATA_OFFSET     0x20

///
/// FPB RID Vector Size Encodings
///
#define FPB_RID_VECTOR_SIZE_256_BITS  0x0
#define FPB_RID_VECTOR_SIZE_1K_BITS   0x2
#define FPB_RID_VECTOR_SIZE_8K_BITS   0x5

///
/// FPB MEM Low Vector Size Encodings
///
#define FPB_MEM_LOW_VECTOR_SIZE_256_BITS  0x0
#define FPB_MEM_LOW_VECTOR_SIZE_512_BITS  0x1
#define FPB_MEM_LOW_VECTOR_SIZE_1K_BITS   0x2
#define FPB_MEM_LOW_VECTOR_SIZE_2K_BITS   0x3
#define FPB_MEM_LOW_VECTOR_SIZE_4K_BITS   0x4

///
/// FPB MEM High Vector Size Encodings
///
#define FPB_MEM_HIGH_VECTOR_SIZE_256_BITS  0x0
#define FPB_MEM_HIGH_VECTOR_SIZE_512_BITS  0x1
#define FPB_MEM_HIGH_VECTOR_SIZE_1K_BITS   0x2
#define FPB_MEM_HIGH_VECTOR_SIZE_2K_BITS   0x3
#define FPB_MEM_HIGH_VECTOR_SIZE_4K_BITS   0x4
#define FPB_MEM_HIGH_VECTOR_SIZE_8K_BITS   0x5

///
/// FPB RID Vector Granularity Encodings
///
#define FPB_RID_GRANULARITY_8_RIDS    0x0
#define FPB_RID_GRANULARITY_64_RIDS   0x3
#define FPB_RID_GRANULARITY_256_RIDS  0x5

///
/// FPB RID Calculation Constants
/// At finest granularity (8 RIDs per bit): 256 RIDs per bus / 8 = 32 bits per bus
///
#define FPB_RIDS_PER_BUS_FINE_GRANULARITY  32

///
/// FPB MEM High Vector Granularity Encodings (PCIe Table 7-196)
///
#define FPB_MEM_HIGH_GRANULARITY_256MB  0x0
#define FPB_MEM_HIGH_GRANULARITY_512MB  0x1
#define FPB_MEM_HIGH_GRANULARITY_1GB    0x2
#define FPB_MEM_HIGH_GRANULARITY_2GB    0x3
#define FPB_MEM_HIGH_GRANULARITY_4GB    0x4
#define FPB_MEM_HIGH_GRANULARITY_8GB    0x5

///
/// FPB MEM Low Vector Granularity Encodings
///
#define FPB_MEM_LOW_GRANULARITY_1MB   0x0
#define FPB_MEM_LOW_GRANULARITY_2MB   0x1
#define FPB_MEM_LOW_GRANULARITY_4MB   0x2
#define FPB_MEM_LOW_GRANULARITY_8MB   0x3
#define FPB_MEM_LOW_GRANULARITY_16MB  0x4

///
/// FPB Vector Select Values
///
#define FPB_VECTOR_SELECT_RID       0x0
#define FPB_VECTOR_SELECT_MEM_LOW   0x1
#define FPB_VECTOR_SELECT_MEM_HIGH  0x2

///
/// FPB Capability Register (Offset 04h)
///
typedef union {
  struct {
    UINT32    RidDecodeMechSupported     : 1;  ///< Bit 0
    UINT32    MemLowDecodeMechSupported  : 1;  ///< Bit 1
    UINT32    MemHighDecodeMechSupported : 1;  ///< Bit 2
    UINT32    NumSecDev                  : 5;  ///< Bits 7:3
    UINT32    RidVectorSizeSupported     : 3;  ///< Bits 10:8
    UINT32    Reserved1                  : 5;  ///< Bits 15:11
    UINT32    MemLowVectorSizeSupported  : 3;  ///< Bits 18:16
    UINT32    Reserved2                  : 5;  ///< Bits 23:19
    UINT32    MemHighVectorSizeSupported : 3;  ///< Bits 26:24
    UINT32    Reserved3                  : 5;  ///< Bits 31:27
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_CAPABILITY_REGISTER;

///
/// FPB RID Vector Control 1 Register (Offset 08h)
///
typedef union {
  struct {
    UINT32    RidDecodeMechEnable  : 1;   ///< Bit 0
    UINT32    Reserved1            : 3;   ///< Bits 3:1
    UINT32    RidVectorGranularity : 4;   ///< Bits 7:4
    UINT32    Reserved2            : 11;  ///< Bits 18:8
    UINT32    RidVectorStart       : 13;  ///< Bits 31:19
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_RID_VECTOR_CTRL1_REG;

///
/// FPB RID Vector Control 2 Register (Offset 0Ch)
///
typedef union {
  struct {
    UINT32    Reserved1         : 3;   ///< Bits 2:0
    UINT32    RidSecondaryStart : 13;  ///< Bits 15:3
    UINT32    Reserved2         : 16;  ///< Bits 31:16
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_RID_VECTOR_CTRL2_REG;

///
/// FPB MEM Low Vector Control Register (Offset 10h)
///
typedef union {
  struct {
    UINT32    MemLowDecodeMechEnable  : 1;   ///< Bit 0
    UINT32    Reserved1               : 3;   ///< Bits 3:1
    UINT32    MemLowVectorGranularity : 4;   ///< Bits 7:4
    UINT32    Reserved2               : 12;  ///< Bits 19:8
    UINT32    MemLowVectorStart       : 12;  ///< Bits 31:20
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_MEM_LOW_VECTOR_CTRL_REG;

///
/// FPB MEM High Vector Control 1 Register (Offset 14h)
///
typedef union {
  struct {
    UINT32    MemHighDecodeMechEnable  : 1;   ///< Bit 0
    UINT32    Reserved1                : 3;   ///< Bits 3:1
    UINT32    MemHighVectorGranularity : 4;   ///< Bits 7:4
    UINT32    Reserved2                : 20;  ///< Bits 27:8
    UINT32    MemHighVectorStartLower  : 4;   ///< Bits 31:28
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_MEM_HIGH_VECTOR_CTRL1_REG;

///
/// FPB MEM High Vector Control 2 Register (Offset 18h)
///
typedef union {
  struct {
    UINT32    MemHighVectorStartUpper : 32;  ///< Bits 31:0
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_MEM_HIGH_VECTOR_CTRL2_REG;

///
/// FPB Vector Access Control Register (Offset 1Ch)
///
typedef union {
  struct {
    UINT32    VectorAccessOffset : 8;   ///< Bits 7:0
    UINT32    Reserved1          : 6;   ///< Bits 13:8
    UINT32    VectorSelect       : 2;   ///< Bits 15:14
    UINT32    Reserved2          : 16;  ///< Bits 31:16
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_VECTOR_ACCESS_CTRL_REG;

///
/// FPB Vector Access Data Register (Offset 20h)
///
typedef union {
  struct {
    UINT32    VectorAccessData : 32;  ///< Bits 31:0
  } Bits;
  UINT32    Uint32;
} PCI_EXPRESS_CAPABILITIES_FPB_VECTOR_ACCESS_DATA_REG;
///@}

#pragma pack()
