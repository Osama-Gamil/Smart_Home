#ifndef BIT_MATH_H
#define BIT_MATH_H

//function get bit
#define GET_BIT(REG,BIT_NU) ((REG>>BIT_NU)&1)

//set bit 
#define SET_BIT(REG,BIT_NU) (REG|=(1<<BIT_NU))

//clear bit 
#define CLR_BIT(REG,BIT_NU) (REG&=(~(1<<BIT_NU)))

//togle 
#define TGL_BIT(REG,BIT_NU) (REG^=(1<<BIT_NU))
//write bit 
#define WRT_BIT(REG,BIT_NU,BIT_VALU)  REG=((REG &(~(1<<BIT_NU))|(BIT_VALU<<BIT_NU)))


#endif