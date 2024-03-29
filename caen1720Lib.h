#ifndef __V1720LIBH__
#define __V1720LIBH__
/*----------------------------------------------------------------------------*
 *  Copyright (c) 2013        Southeastern Universities Research Association, *
 *                            Thomas Jefferson National Accelerator Facility  *
 *                                                                            *
 *    This software was developed under a United States Government license    *
 *    described in the NOTICE file included as part of this distribution.     *
 *                                                                            *
 *    Authors: Bryan Moffit                                                   *
 *             moffit@jlab.org                   Jefferson Lab, MS-12B3       *
 *             Phone: (757) 269-5660             12000 Jefferson Ave.         *
 *             Fax:   (757) 269-5800             Newport News, VA 23606       *
 *                                                                            *
 *             Robert Michaels                                                *
 *             rom@jlab.org                      Jefferson Lab, MS-12B3       *
 *             Phone: (757) 269-7410             12000 Jefferson Ave.         *
 *                                               Newport News, VA 23606       *
 *                                                                            *
 *----------------------------------------------------------------------------*
 *
 * Description:
 *     Header for Library for the CAEN 1720 FADC 
 *
 * SVN: $Rev$
 *
 *----------------------------------------------------------------------------*/

#define C1720_MAX_BOARDS         8
#define C1720_MAX_ADC_CHANNELS   8

/* Board ID as obtained from configuration rom 
   = (board0<<16) | (board1<<8) | (board2) */
#define C1720_BOARD_ID      0xB80600
#define C1720_BOARD_ID_MASK 0xFFFFFE

/* Infomation related to each channel (in address map below) */
struct c1720_chan 
{  /* 64 long words, 256 bytes */
  /* 0x1n80 */ volatile unsigned int thresh;
  /* 0x1n84 */ volatile unsigned int time_overunder;
  /* 0x1n88 */ volatile unsigned int status;
  /* 0x1n8C */ volatile unsigned int fpga_firmware;
  /* 0x1n90 */          unsigned int dummy1;
  /* 0x1n94 */ volatile unsigned int buffer_occupancy;
  /* 0x1n98 */ volatile unsigned int dac;
  /* 0x1n9C */ volatile unsigned int adc_config;
  /* 0x1nA0 */          unsigned int dummy2[(0x1180-0x10A0)/4];
};


/* Configuration ROM  (in address map below) */
struct c1720_romAddr 
{   /* size: 88 bytes  */
  /* 0xF000 */ volatile unsigned int checksum;
  /* 0xF004 */ volatile unsigned int checksum_length2;
  /* 0xF008 */ volatile unsigned int checksum_length1;
  /* 0xF00C */ volatile unsigned int checksum_length0;
  /* 0xF010 */ volatile unsigned int constant2;
  /* 0xF014 */ volatile unsigned int constant1;
  /* 0xF018 */ volatile unsigned int constant0;
  /* 0xF01C */ volatile unsigned int c_code;
  /* 0xF020 */ volatile unsigned int r_code;
  /* 0xF024 */ volatile unsigned int oui2;
  /* 0xF028 */ volatile unsigned int oui1;
  /* 0xF02C */ volatile unsigned int oui0;
  /* 0xF030 */ volatile unsigned int vers;
  /* 0xF034 */ volatile unsigned int board2;
  /* 0xF038 */ volatile unsigned int board1;
  /* 0xF03C */ volatile unsigned int board0;
  /* 0xF040 */ volatile unsigned int revis3;
  /* 0xF044 */ volatile unsigned int revis2;
  /* 0xF048 */ volatile unsigned int revis1;
  /* 0xF04C */ volatile unsigned int revis0;
  /* 0xF050 */          unsigned int dummy1[(0xF080-0xF050)/4];
  /* 0xF080 */ volatile unsigned int sernum1;
  /* 0xF084 */ volatile unsigned int sernum0;
};  

/* Registers address map of CAEN 1720 */
struct c1720_address 
{
  /* 0x0000 */ volatile unsigned int readout_buffer[(0x1000-0x0000)/4];
  /* 0x1000 */          unsigned int dummy1[(0x1080-0x1000)/4];
  /* 0x1080 */ volatile struct c1720_chan chan[8];
  /* 0xnnnn */          unsigned int dummy2[(0x8000-0x1880)/4];
  /* 0x8000 */ volatile unsigned int chan_config;
  /* 0x8004 */ volatile unsigned int config_bitset;
  /* 0x8008 */ volatile unsigned int config_bitclear;
  /* 0x800C */ volatile unsigned int buffer_org;
  /* 0x8010 */ volatile unsigned int buffer_free;
  /* 0x8014 */          unsigned int dummy3[(0x8020-0x8014)/4];
  /* 0x8020 */ volatile unsigned int buffer_size;
  /* 0x8024 */          unsigned int dummy3a[(0x8100-0x8024)/4];
  /* 0x8100 */ volatile unsigned int acq_ctrl;
  /* 0x8104 */ volatile unsigned int acq_status;
  /* 0x8108 */ volatile unsigned int sw_trigger;
  /* 0x810C */ volatile unsigned int trigmask_enable;
  /* 0x8110 */ volatile unsigned int tmask_out;
  /* 0x8114 */ volatile unsigned int post_trigset;
  /* 0x8118 */ volatile unsigned int fio_data;
  /* 0x811C */ volatile unsigned int fio_ctrl;
  /* 0x8120 */ volatile unsigned int enable_mask;
  /* 0x8124 */ volatile unsigned int firmware;
  /* 0x8128 */ volatile unsigned int downsamp_fact;
  /* 0x812C */ volatile unsigned int event_stored;
  /* 0x8130 */          unsigned int dummy4[(0x8138-0x8130)/4];
  /* 0x8138 */ volatile unsigned int monitor_dac;
  /* 0x813C */          unsigned int dummy5;
  /* 0x8140 */ volatile unsigned int board_info;
  /* 0x8144 */ volatile unsigned int monitor_mode;
  /* 0x8148 */          unsigned int dummy6;
  /* 0x814C */ volatile unsigned int event_size;
  /* 0x8150 */          unsigned int dummy7[(0xEF00-0x8150)/4];
  /* 0xEF00 */ volatile unsigned int vme_ctrl;
  /* 0xEF04 */ volatile unsigned int vme_status;
  /* 0xEF08 */ volatile unsigned int board_id;
  /* 0xEF0C */ volatile unsigned int multi_addrctrl;
  /* 0xEF10 */ volatile unsigned int reloc_addr;
  /* 0xEF14 */ volatile unsigned int interrupt_id;
  /* 0xEF18 */ volatile unsigned int interrupt_num;
  /* 0xEF1C */ volatile unsigned int blt_evnum;
  /* 0xEF20 */ volatile unsigned int scratch;
  /* 0xEF24 */ volatile unsigned int sw_reset;
  /* 0xEF28 */ volatile unsigned int sw_clear;
  /* 0xEF2C */ volatile unsigned int flash_enable;
  /* 0xEF30 */ volatile unsigned int flash_data;
  /* 0xEF34 */ volatile unsigned int config_reload;
  /* 0xEF38 */          unsigned int dummy8[(0xF000-0xEF38)/4];
  /* 0xF000 */ volatile struct c1720_romAddr rom;

};

/* chan_config masks and bits */
#define C1720_CHAN_CONFIG_TRIG_OVERLAP            (1<<1)
#define C1720_CHAN_CONFIG_TEST_PATTERN            (1<<3)
#define C1720_CHAN_CONFIG_MEM_SEQUENTIAL          (1<<4)
#define C1720_CHAN_CONFIG_TRIGOUT_UNDER_THRESHOLD (1<<6)
#define C1720_CHAN_CONFIG_PACK2_5                 (1<<11)
#define C1720_CHAN_CONFIG_ZERO_SUPPRESSION_MASK   0x000F0000
#define C1720_CHAN_CONFIG_ZLE                     (1<<16)
#define C1720_CHAN_CONFIG_ZS_AMP                  ((1<<16)|(1<<17))

/* trigmask_enable masks and bits */
#define C1720_TRIGMASK_ENABLE_SOFTWARE         (1<<31)
#define C1720_TRIGMASK_ENABLE_EXTERNAL         (1<<30)
#define C1720_TRIGMASK_ENABLE_COINC_LEVEL_MASK 0x07000000
#define C1720_TRIGMASK_ENABLE_CHANNEL_MASK     0x000000FF

/* enable_mask mask */
#define C1720_ENABLE_CHANNEL_MASK     0x000000FF


/* Source options for c1720EnableTriggerSource/c1720DisableTriggerSource */
#define C1720_SOFTWARE_TRIGGER_ENABLE 0
#define C1720_EXTERNAL_TRIGGER_ENABLE 1
#define C1720_CHANNEL_TRIGGER_ENABLE  2
#define C1720_ALL_TRIGGER_ENABLE      3

/* acq_status Masks and bits */
#define C1720_ACQ_STATUS_RUN_ENABLED  (1<<2)
#define C1720_ACQ_STATUS_EVENT_READY  (1<<3)
#define C1720_ACQ_STATUS_EVENT_FULL   (1<<4)
#define C1720_ACQ_STATUS_CLK_EXTERNAL (1<<5)
#define C1720_ACQ_STATUS_PLL_BYPASS   (1<<6)
#define C1720_ACQ_STATUS_PLL_LOCKED   (1<<7)
#define C1720_ACQ_STATUS_ACQ_READY    (1<<8)

/* vme_ctrl Masks and bits */
#define C1720_VME_CTRL_INTLEVEL_MASK   0x7
#define C1720_VME_CTRL_BERR_ENABLE    (1<<4)
#define C1720_VME_CTRL_ALIGN64_ENABLE (1<<5)
#define C1720_VME_CTRL_RELOC_ENABLE   (1<<6)
#define C1720_VME_CTRL_ROAK_ENABLE    (1<<7)

/* vme_status Masks and bits */
#define C1720_VME_STATUS_EVENT_READY        (1<<0)
#define C1720_VME_STATUS_OUTPUT_BUFFER_FULL (1<<1)
#define C1720_VME_STATUS_BERR_OCCURRED      (1<<2)

/* monitor_mode bits*/
#define C1720_MONITOR_MODE_MASK       0x7
#define C1720_MONITOR_MODE_MAJORITY   0
#define C1720_MONITOR_MODE_WAVEFORM   1
#define C1720_MONITOR_MODE_BUFFER_OCC 3
#define C1720_MONITOR_MODE_VOLT_LEVEL 4

#define C1720_MONITOR_DAC_MASK 0xFFF

/* Channel specific regs masks and bits */
#define C1720_CHANNEL_THRESHOLD_MASK  0x00000FFF

#define C1720_CHANNEL_TIME_OVERUNDER_MASK 0x00000FFF

#define C1720_CHANNEL_STATUS_MEM_FULL     (1<<0)
#define C1720_CHANNEL_STATUS_MEM_EMPY     (1<<1)
#define C1720_CHANNEL_STATUS_BUSY         (1<<2)
#define C1720_CHANNEL_STATUS_BUFFER_ERROR (1<<5)



/* Event structure masks and bits */
/* Header: 1st word */
#define C1720_HEADER_TYPE_MASK        0xF0000000
#define C1720_HEADER_TYPE_ID          0xA0000000
#define C1720_HEADER_EVENTSIZE_MASK   0x0FFFFFFF
/* Header: 2nd word */
#define C1720_HEADER_BOARDID_MASK     0xF8000000
#define C1720_HEADER_ZLE_FORMAT       (1<<24)
#define C1720_HEADER_BIT_PATTERN_MASK 0x00FFFF00
#define C1720_HEADER_CHANNEL_MASK     0x000000FF
/* Header: 3rd word */
#define C1720_HEADER_EVENT_CNT_MASK   0x00FFFFFF
/* Header: 4th word */
#define C1720_HEADER_TRIGTIME_MASK    0xFFFFFFFF



/* Function prototypes */

STATUS c1720Init(UINT32 addr, UINT32 addr_inc, int nadc);
int c1720PrintChanStatus(int id, int chan);
int c1720PrintStatus(int id);
int c1720Reset(int id);
int c1720Clear(int id);
int c1720SoftTrigger(int id);
int c1720SetTriggerOverlapping(int id, int enable);
int c1720SetTestPatternGeneration(int id, int enable);
int c1720SetTriggerOnUnderThreshold(int id, int enable);
int c1720SetPack2_5(int id, int enable);
int c1720SetZeroLengthEncoding(int id, int enable);
int c1720SetAmplitudeBasedFullSuppression(int id, int enable);
int c1720EnableTriggerSource(int id, int src, int chanmask, int level);
int c1720DisableTriggerSource(int id, int src, int chanmask);
int c1720EnableFPTrigOut(int id, int src, int chanmask);
int c1720DisableFPTrigOut(int id, int src, int chanmask);
int c1720SetEnableChannelMask(int id, int chanmask);
unsigned int c1720GetEventSize(int id);
unsigned int c1720GetNumEv(int id);
int c1720SetChannelDAC(int id, int chan, int dac);
int c1720BufferFree(int id, int num);
int c1720SetAcqCtrl(int id, int bits);
int c1720SetPostTrig(int id, int val);
int c1720BoardReady(int id);
int c1720EventReady(int id);
int c1720SetBufOrg(int id, int code);
int c1720SetBufferSize(int id, int val);
int c1720SetBusError(int id, int enable);
int c1720SetAlign64(int id, int enable);
int c1720SetChannelThreshold(int id, int chan, int thresh);
int c1720SetChannelTimeOverUnder(int id, int chan, int samp);
int c1720SetMonitorMode(int id, int mode);
int c1720SetMonitorDAC(int id, int dac);
int c1720SetupInterrupt(int id, int level, int vector);
int c1720EnableInterrupts(int id);
int c1720DisableInterrupts(int id);

int c1720ReadEvent(int id, volatile unsigned int *data, int nwrds, int rflag);

/* Start of some test code */

int c1720DefaultSetup(int id);
int c1720StartRun(int id);
int c1720StopRun(int id);

int c1720Test1();
int c1720Test1a();
int c1720Test1b();
int c1720Test2();
int c1720Test2a();
int c1720Test2b();
int c1720Test3();

int c1720TestPrintBuffer();
int c1720PrintBuffer();

int c1720Test4();

// These dont exist... wonder where they are.. (Bryan)
/* int c1720_Read_Channel(unsigned int id, */
/*                        unsigned int chan, */
/*                        unsigned int* buffer, */
/*                        unsigned int bufflen); */

/* int c1720GetAccum(int id, int chan); */



#endif /* __V1720LIBH__ */
