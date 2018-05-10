/**
* MIT License
* 
* Copyright (c) 2017 Viral Security Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* @file        cr64.h
* @section    Intel x64 Control Registers
*/

#ifndef __INTEL_CR64_H__
#define __INTEL_CR64_H__

#include "ntdatatypes.h"

// Disable 'warning C4214: nonstandard extension used: bit field types other than int'
// Disable 'warning C4201: nonstandard extension used: nameless struct/union'
#pragma warning(push)
#pragma warning( disable : 4214)
#pragma warning( disable : 4201)
#pragma pack(push, 1)

//! Figure 2-7. Control Registers
typedef union _CR0_REG
{
    UINT32 dwValue;
    struct {
        UINT32 Pe : 1;          //!< 0      protected mode enable
        UINT32 Mp : 1;          //!< 1      monitor co - processor
        UINT32 Em : 1;          //!< 2      emulation
        UINT32 Ts : 1;          //!< 3      task switched
        UINT32 Et : 1;          //!< 4      extension type
        UINT32 Ne : 1;          //!< 5      numeric error
        UINT32 Reserved0 : 10;  //!< 6-15    
        UINT32 Wp : 1;          //!< 16     write protect
        UINT32 Reserved1 : 1;   //!< 17    
        UINT32 Am : 1;          //!< 18     alignment mask
        UINT32 Reserved2 : 10;  //!< 19-28
        UINT32 Nw : 1;          //!< 29     not- write through
        UINT32 Cd : 1;          //!< 30     cache disable
        UINT32 Pg : 1;          //!< 31     paging
    };
} CR0_REG, *PCR0_REG;
C_ASSERT(sizeof(UINT32) == sizeof(CR0_REG));

//! Figure 2-7. Control Registers
typedef union _CR4_REG
{
    UINT32 dwValue;
    struct {
        UINT32 Vme : 1;         //!< 0      virtual 8086 mode extensions
        UINT32 Pvi : 1;         //!< 1      protected mode virtual interrupts
        UINT32 Tsd : 1;         //!< 2      time stamp disable
        UINT32 De : 1;          //!< 3      debugging extensions
        UINT32 Pse : 1;         //!< 4      page size extension
        UINT32 Pae : 1;         //!< 5      physical address extension
        UINT32 Mce : 1;         //!< 6      machine check exception
        UINT32 Pge : 1;         //!< 7      page global enable
        UINT32 Pce : 1;         //!< 8      performance monitoring counter enable
        UINT32 Osfxsr : 1;      //!< 9      os support for fxsave and fxrstor instructions
        UINT32 Osxmmexcpt : 1;  //!< 10     os support for unmasked simd floating point exceptions
        UINT32 Reserved0 : 2;   //!< 11-12
        UINT32 Vmxe : 1;        //!< 13     virtual machine extensions enable
        UINT32 Smxe : 1;        //!< 14     safer mode extensions enable
        UINT32 Reserved1 : 2;   //!< 15-16
        UINT32 Pcide : 1;       //!< 17     pcid enable
        UINT32 Osxsave : 1;     //!< 18     xsave and processor extended states enable
        UINT32 Reserved2 : 1;   //!< 19
        UINT32 Smep : 1;        //!< 20     supervisor mode executions protection enable
        UINT32 Smap : 1;        //!< 21     supervisor mode access protection enable
        UINT32 Pke : 1;         //!< 22     associate each linear address with a protection 
                                //          key (PKRU)
        UINT32 reserved3 : 9;   //!< 23-31
    };
} CR4_REG, *PCR4_REG;
C_ASSERT(sizeof(UINT32) == sizeof(CR4_REG));

typedef union _CR3_REG
{
    UINT64 qwValue;

 //! Vol 3A, Table 4-12. Use of CR3 with IA-32e Paging and CR4.PCIDE = 0
    struct {
        UINT64 Reserved0 : 3;   //!< 0-2
        UINT64 Pwt : 1;         //!< 3      Page-level Write-Through
        UINT64 Pcd : 1;         //!< 4      Page-level Cache Disable 
        UINT64 Reserved1 : 7;   //!< 5-11
        UINT64 Pml4 : 52;       //!< 12-63  PML4 table physical address
    } NoPcid;

 //! Vol 3A, Table 4-13. Use of CR3 with IA-32e Paging and CR4.PCIDE = 1
    struct {
        UINT64 Pcid : 12;       //!< 5-11
        UINT64 Pml4 : 52;       //!< 12-63  PML4 table physical address
    } Pcid;
} CR3_REG, *PCR3_REG;
C_ASSERT(sizeof(UINT64) == sizeof(CR3_REG));

#pragma pack(pop)
#pragma warning(pop)
#endif /* __INTEL_CR64_H__ */
