/*
 * Copyright (C) 2010 ARM Limited. All rights reserved.
 * 
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 * 
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__
/* Configuration for the EB platform with ZBT memory enabled */
/*zepplin added 2010.08.17 for orion configuration*/
#define MALI_BASE_ADDR 		   0x13000000
#define GP_ADDR 	MALI_BASE_ADDR
#define L2_ADDR 	MALI_BASE_ADDR+0x1000
#define PMU_ADDR 	MALI_BASE_ADDR+0x2000
#define GP_MMU_ADDR 	MALI_BASE_ADDR+0x3000
#define PP0_MMU_ADDR 	MALI_BASE_ADDR+0x4000
#define PP1_MMU_ADDR 	MALI_BASE_ADDR+0x5000
#define PP2_MMU_ADDR 	MALI_BASE_ADDR+0x6000
#define PP3_MMU_ADDR 	MALI_BASE_ADDR+0x7000
#define PP0_ADDR 	MALI_BASE_ADDR+0x8000
#define PP1_ADDR 	MALI_BASE_ADDR+0xA000
#define PP2_ADDR 	MALI_BASE_ADDR+0xC000
#define PP3_ADDR 	MALI_BASE_ADDR+0xE000

/*for mmu and os memory*/
#define MEM_BASE_ADDR    0x40000000
#define MEM_TOTAL_SIZE   0x40000000
#define MEM_MALI_OS_SIZE 0x40000000

/*for dedicated memory*/
#define MEM_MALI_SIZE 	 256*1024*1024
//#define MEM_MALI_BASE    0x60000000 - MEM_MALI_SIZE 
#define MEM_MALI_BASE	 0x13000000

#define IRQ_SPI(x)              (x+32)
#define IRQ_PPMMU0_3D           IRQ_SPI(118)
#define IRQ_PPMMU1_3D           IRQ_SPI(119)
#define IRQ_PPMMU2_3D           IRQ_SPI(120)
#define IRQ_PPMMU3_3D           IRQ_SPI(121)
#define IRQ_GPMMU_3D            IRQ_SPI(122)
                
#define IRQ_PP0_3D              IRQ_SPI(123)
#define IRQ_PP1_3D              IRQ_SPI(124)
#define IRQ_PP2_3D              IRQ_SPI(125)
#define IRQ_PP3_3D              IRQ_SPI(126)
#define IRQ_GP_3D               IRQ_SPI(127)
#define IRQ_PMU_3D              IRQ_SPI(117)



#endif /* __ARCH_CONFIG_H__ */
