/*
 * GENERATED FILE - DO NOT EDIT
 * (C) Code Red Technologies Ltd, 2008-2014
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v5.2.2 [Build 2108] [2013-04-17]  on Wed Jun 18 08:31:17 ART 2014)
*/

MEMORY
{
  /* Define each memory region */
  MFlash512 (rx) : ORIGIN = 0x0, LENGTH = 0x80000 /* 512k */
  RamLoc32 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x8000 /* 32k */
  RamAHB32 (rwx) : ORIGIN = 0x2007c000, LENGTH = 0x8000 /* 32k */

}
  /* Define a symbol for the top of each memory region */
  __top_MFlash512 = 0x0 + 0x80000;
  __top_RamLoc32 = 0x10000000 + 0x8000;
  __top_RamAHB32 = 0x2007c000 + 0x8000;

