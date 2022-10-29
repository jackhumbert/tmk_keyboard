/* Copyright 2021 JasonRen(biu)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "progmem.h"

/*
 !(0) "(1) #(2) $(3) %(4) &(5) '(6) ((7)
 )(8) *(9) +(10) ,(11) -(12) .(13) /(14) 0(15)
 1(16) 2(17) 3(18) 4(19) 5(20) 6(21) 7(22) 8(23)
 9(24) :(25) ;(26) <(27) =(28) >(29) ?(30) @(31)
 A(32) B(33) C(34) D(35) E(36) F(37) G(38) H(39)
 I(40) J(41) K(42) L(43) M(44) N(45) O(46) P(47)
 Q(48) R(49) S(50) T(51) U(52) V(53) W(54) X(55)
 Y(56) Z(57) [(58) \(59) ](60) ^(61) _(62) `(63)
 a(64) b(65) c(66) d(67) e(68) f(69) g(70) h(71)
 i(72) j(73) k(74) l(75) m(76) n(77) o(78) p(79)
 q(80) r(81) s(82) t(83) u(84) v(85) w(86) x(87)
 y(88) z(89) {(90) |(91) }(92) ~(93)  (94)
 */

static const unsigned char ext_big_font[95][24] PROGMEM = {
{0x00,0x00,0x00,0x00,0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x1B,0x1B,0x1B,0x00,0x00,0x00,0x00},/*"!",0*/
{0x00,0x00,0x00,0x18,0xF8,0x18,0x00,0x18,0xF8,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",1*/
{0x00,0x00,0x60,0x60,0xFE,0xFE,0x60,0xFE,0xFE,0x60,0x00,0x00,0x00,0x00,0x06,0x7F,0x7F,0x06,0x7F,0x7F,0x06,0x06,0x00,0x00},/*"#",2*/
{0x00,0x00,0x00,0xF0,0xF8,0x9E,0x9E,0xB8,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0xF9,0xF9,0x1F,0x0F,0x00,0x00,0x00},/*"$",3*/
{0x00,0x00,0x38,0x44,0xC4,0xC4,0xB8,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x0E,0x11,0x11,0x11,0x0E,0x00,0x00,0x00},/*"%",4*/
{0x00,0x00,0x60,0xE0,0xB0,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x0E,0x0F,0x19,0x19,0x1B,0x1E,0x0E,0x0F,0x1B,0x00,0x00},/*"&",5*/
{0x00,0x00,0x00,0x00,0x00,0x18,0xF8,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",6*/
{0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0x3C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x78,0x60,0x00,0x00,0x00},/*"(",7*/
{0x00,0x00,0x0C,0x3C,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x78,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x00},/*")",8*/
{0x00,0x00,0x30,0xB0,0xF0,0xFC,0xFC,0xF0,0xB0,0x30,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x01,0x01,0x00,0x00,0x00},/*"*",9*/
{0x00,0x80,0x80,0x80,0x80,0xF8,0xF8,0x80,0x80,0x80,0x80,0x00,0x00,0x01,0x01,0x01,0x01,0x1F,0x1F,0x01,0x01,0x01,0x01,0x00},/*"+",10*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x38,0x08,0x00,0x00,0x00,0x00,0x00},/*",",11*/
{0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00},/*"-",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00},/*".",13*/
{0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0x78,0x1E,0x06,0x00,0x00,0x00,0x00,0x60,0x78,0x1E,0x07,0x01,0x00,0x00,0x00,0x00,0x00},/*"/",14*/
{0x00,0x00,0xF0,0xF8,0x1C,0x0C,0x1C,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0x1C,0x0F,0x07,0x00,0x00,0x00},/*"0",15*/
{0x00,0x00,0x18,0x18,0x18,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00},/*"1",16*/
{0x00,0x00,0x30,0x38,0x0C,0x0C,0x8C,0xF8,0x70,0x00,0x00,0x00,0x00,0x00,0x18,0x1C,0x1E,0x1B,0x19,0x18,0x18,0x00,0x00,0x00},/*"2",17*/
{0x00,0x00,0x18,0x1C,0xCC,0xCC,0xCC,0xFC,0x38,0x00,0x00,0x00,0x00,0x0C,0x1C,0x18,0x18,0x18,0x19,0x0F,0x07,0x00,0x00,0x00},/*"3",18*/
{0x00,0x00,0xC0,0xE0,0x78,0x1C,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x1B,0x1B,0x1F,0x1F,0x1B,0x00,0x00,0x00},/*"4",19*/
{0x00,0x00,0xFC,0xFC,0xCC,0xCC,0xCC,0x8C,0x00,0x00,0x00,0x00,0x00,0x0C,0x1C,0x18,0x18,0x18,0x18,0x0F,0x07,0x00,0x00,0x00},/*"5",20*/
{0x00,0x00,0xE0,0xF0,0xB8,0xDC,0xCC,0xCC,0x8C,0x00,0x00,0x00,0x00,0x00,0x07,0x0F,0x19,0x18,0x18,0x1F,0x0F,0x00,0x00,0x00},/*"6",21*/
{0x00,0x00,0x1C,0x1C,0x0C,0x0C,0xCC,0xFC,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1F,0x03,0x00,0x00,0x00,0x00},/*"7",22*/
{0x00,0x00,0x38,0xFC,0xCC,0xCC,0xCC,0xFC,0x38,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x18,0x18,0x18,0x1F,0x0F,0x00,0x00,0x00},/*"8",23*/
{0x00,0x00,0xF8,0xFC,0x8C,0x8C,0xCC,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x18,0x19,0x19,0x1D,0x0E,0x07,0x03,0x00,0x00,0x00},/*"9",24*/
{0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00,0x00},/*":",25*/
{0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x18,0x08,0x00,0x00,0x00,0x00,0x00},/*";",26*/
{0x00,0x00,0x00,0x80,0x80,0xC0,0x60,0x60,0x30,0x30,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x06,0x0C,0x0C,0x18,0x18,0x00,0x00},/*"<",27*/
{0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x00,0x00},/*"=",28*/
{0x00,0x30,0x30,0x60,0x60,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x0C,0x0C,0x06,0x03,0x03,0x01,0x01,0x00,0x00},/*">",29*/
{0x00,0x00,0x70,0x78,0x18,0x18,0x98,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x1B,0x01,0x01,0x00,0x00,0x00,0x00},/*"?",30*/
{0x00,0x00,0xF0,0x08,0xC4,0x24,0x24,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x10,0x21,0x22,0x22,0x13,0x00,0x00,0x00,0x00},/*"@",31*/
{0x00,0x00,0x18,0x98,0xF8,0x38,0x38,0xF0,0x80,0x00,0x00,0x00,0x00,0x18,0x1C,0x1F,0x1B,0x03,0x03,0x1B,0x1F,0x1C,0x18,0x00},/*"A",32*/
{0x00,0x18,0xF8,0xF8,0x98,0x98,0x98,0xF8,0x70,0x00,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x19,0x19,0x19,0x1F,0x0E,0x00,0x00},/*"B",33*/
{0x00,0xE0,0xF0,0x38,0x18,0x18,0x18,0x10,0x78,0x78,0x00,0x00,0x00,0x07,0x0F,0x0C,0x18,0x18,0x18,0x18,0x0C,0x0C,0x00,0x00},/*"C",34*/
{0x00,0x18,0xF8,0xF8,0x18,0x18,0x18,0x38,0xF0,0xE0,0x00,0x00,0x00,0x18,0x1F,0x1F,0x18,0x18,0x18,0x1C,0x0F,0x07,0x00,0x00},/*"D",35*/
{0x00,0x18,0xF8,0xF8,0x98,0xD8,0xD8,0x18,0x78,0x78,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x1B,0x1B,0x18,0x1E,0x1E,0x00,0x00},/*"E",36*/
{0x00,0x18,0xF8,0xF8,0x98,0xD8,0xD8,0x18,0x78,0x78,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x1B,0x1B,0x00,0x00,0x00,0x00,0x00},/*"F",37*/
{0x00,0xE0,0xF0,0x38,0x18,0x18,0x10,0x38,0x38,0x00,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0x1B,0x1B,0x1F,0x0F,0x03,0x00,0x00},/*"G",38*/
{0x00,0x18,0xF8,0xF8,0x98,0x80,0x98,0xF8,0xF8,0x18,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x01,0x19,0x1F,0x1F,0x18,0x00,0x00},/*"H",39*/
{0x00,0x00,0x18,0x18,0x18,0xF8,0xF8,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00},/*"I",40*/
{0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xF8,0xF8,0x18,0x18,0x00,0x00,0x00,0x0F,0x0F,0x18,0x18,0x18,0x0F,0x0F,0x00,0x00,0x00},/*"J",41*/
{0x00,0x18,0xF8,0xF8,0x98,0xC0,0x78,0x38,0x18,0x18,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x01,0x07,0x1E,0x18,0x18,0x00,0x00},/*"K",42*/
{0x00,0x18,0x18,0xF8,0xF8,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x1F,0x1F,0x00,0x00},/*"L",43*/
{0x18,0xF8,0xF8,0x38,0xE0,0x00,0xE0,0x38,0xF8,0xF8,0x18,0x00,0x18,0x1F,0x1F,0x18,0x19,0x03,0x19,0x18,0x1F,0x1F,0x18,0x00},/*"M",44*/
{0x00,0x18,0xF8,0xF8,0xF8,0xE0,0x18,0xF8,0xF8,0x18,0x00,0x00,0x00,0x18,0x1F,0x1F,0x18,0x03,0x1F,0x1F,0x1F,0x00,0x00,0x00},/*"N",45*/
{0x00,0xC0,0xF0,0x30,0x18,0x18,0x18,0x30,0xF0,0xC0,0x00,0x00,0x00,0x03,0x0F,0x0C,0x18,0x18,0x18,0x0C,0x0F,0x03,0x00,0x00},/*"O",46*/
{0x00,0x18,0xF8,0xF8,0x98,0x98,0x98,0xF8,0xF0,0x00,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x19,0x19,0x01,0x00,0x00,0x00,0x00},/*"P",47*/
{0x00,0xC0,0xF0,0x30,0x18,0x18,0x18,0x30,0xF0,0xC0,0x00,0x00,0x00,0x03,0x0F,0xCC,0xF8,0x78,0x78,0xCC,0xEF,0x63,0x00,0x00},/*"Q",48*/
{0x00,0x18,0xF8,0xF8,0x98,0x98,0x98,0xF8,0x70,0x00,0x00,0x00,0x00,0x18,0x1F,0x1F,0x19,0x1B,0x07,0x0E,0x1C,0x18,0x00,0x00},/*"R",49*/
{0x00,0x00,0x70,0xF8,0x98,0x98,0x90,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x09,0x19,0x19,0x1F,0x0E,0x00,0x00,0x00},/*"S",50*/
{0x00,0xF8,0xF8,0x18,0x18,0xF8,0xF8,0x18,0x18,0xF8,0xF8,0x00,0x00,0x00,0x00,0x18,0x18,0x1F,0x1F,0x18,0x18,0x00,0x00,0x00},/*"T",51*/
{0x00,0x18,0xF8,0xF8,0x18,0x00,0x18,0xF8,0xF8,0x18,0x00,0x00,0x00,0x00,0x07,0x0F,0x18,0x18,0x18,0x0F,0x07,0x00,0x00,0x00},/*"U",52*/
{0x00,0x18,0x78,0xF8,0x98,0x00,0x98,0xF8,0x78,0x18,0x00,0x00,0x00,0x00,0x00,0x03,0x1F,0x18,0x1F,0x03,0x00,0x00,0x00,0x00},/*"V",53*/
{0x18,0xF8,0xF8,0x18,0xD8,0xC0,0xD8,0x18,0xF8,0xF8,0x18,0x00,0x00,0x01,0x1F,0x1C,0x1F,0x01,0x1F,0x1C,0x1F,0x01,0x00,0x00},/*"W",54*/
{0x00,0x18,0x38,0x78,0xD8,0x80,0xD8,0x78,0x38,0x18,0x00,0x00,0x00,0x18,0x1C,0x1E,0x1B,0x01,0x1B,0x1E,0x1C,0x18,0x00,0x00},/*"X",55*/
{0x00,0x18,0x38,0x78,0xD8,0x80,0x80,0xD8,0x78,0x38,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x1F,0x1F,0x18,0x18,0x00,0x00,0x00},/*"Y",56*/
{0x00,0x00,0x78,0x78,0x18,0x98,0xD8,0x78,0x38,0x00,0x00,0x00,0x00,0x00,0x1C,0x1E,0x1B,0x19,0x18,0x1E,0x1E,0x00,0x00,0x00},/*"Z",57*/
{0x00,0x00,0x00,0x00,0x00,0xFC,0xFC,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x60,0x60,0x00,0x00,0x00},/*"[",58*/
{0x00,0x00,0x06,0x1E,0x78,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x1E,0x78,0x60,0x00,0x00},/*"\",59*/
{0x00,0x00,0x00,0x0C,0x0C,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00},/*"]",60*/
{0x00,0x00,0x00,0x60,0x70,0x18,0x0C,0x18,0x70,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",61*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"_",62*/
{0x00,0x00,0x00,0x00,0x02,0x04,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",63*/
{0x00,0x00,0x00,0x60,0x60,0x60,0x60,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x0E,0x1F,0x1B,0x1B,0x0B,0x1F,0x1F,0x18,0x00,0x00},/*"a",64*/
{0x00,0x0C,0xFC,0xFC,0xC0,0x60,0x60,0xE0,0xC0,0x80,0x00,0x00,0x00,0x18,0x1F,0x1F,0x0C,0x18,0x18,0x1C,0x0F,0x07,0x00,0x00},/*"b",65*/
{0x00,0x00,0x80,0xC0,0xE0,0x60,0x60,0x60,0xC0,0xE0,0x00,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0x18,0x18,0x18,0x0C,0x00,0x00},/*"c",66*/
{0x00,0x00,0x80,0xC0,0xE0,0x60,0x60,0xCC,0xFC,0xFC,0x00,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0x18,0x0C,0x1F,0x1F,0x18,0x00},/*"d",67*/
{0x00,0x00,0x80,0xC0,0x60,0x60,0x60,0x60,0xC0,0x80,0x00,0x00,0x00,0x00,0x07,0x0F,0x1B,0x1B,0x1B,0x1B,0x1B,0x0B,0x00,0x00},/*"e",68*/
{0x00,0x00,0x60,0x60,0xF8,0xFC,0x6C,0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00,0x00},/*"f",69*/
{0x00,0x00,0x80,0xC0,0xE0,0x60,0x60,0xC0,0xE0,0xE0,0x60,0x00,0x00,0x00,0x07,0x0F,0xDC,0xD8,0xD8,0xCC,0xFF,0x7F,0x00,0x00},/*"g",70*/
{0x00,0x0C,0xFC,0xFC,0xC0,0x60,0x60,0x60,0xE0,0xC0,0x00,0x00,0x00,0x18,0x1F,0x1F,0x18,0x00,0x00,0x18,0x1F,0x1F,0x18,0x00},/*"h",71*/
{0x00,0x00,0x00,0x60,0x60,0xEC,0xEC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00},/*"i",72*/
{0x00,0x00,0x60,0x60,0x60,0x6C,0x6C,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0x7F,0x00,0x00,0x00},/*"j",73*/
{0x00,0x00,0x0C,0xFC,0xFC,0x80,0xE0,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x18,0x1F,0x1F,0x03,0x06,0x1C,0x18,0x18,0x00,0x00},/*"k",74*/
{0x00,0x00,0x00,0x0C,0x0C,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00},/*"l",75*/
{0x00,0x60,0xE0,0xE0,0x60,0xE0,0xC0,0x60,0xE0,0xC0,0x00,0x00,0x00,0x18,0x1F,0x1F,0x00,0x1F,0x1F,0x00,0x1F,0x1F,0x18,0x00},/*"m",76*/
{0x00,0x60,0xE0,0xE0,0xC0,0x60,0x60,0x60,0xE0,0xC0,0x00,0x00,0x00,0x18,0x1F,0x1F,0x18,0x00,0x00,0x18,0x1F,0x1F,0x18,0x00},/*"n",77*/
{0x00,0x00,0x80,0xC0,0xE0,0x60,0x60,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0x18,0x1C,0x0F,0x07,0x00,0x00},/*"o",78*/
{0x00,0x60,0xE0,0xE0,0xC0,0x60,0x60,0xE0,0xC0,0x80,0x00,0x00,0x00,0xC0,0xFF,0xFF,0xCC,0xD8,0x18,0x1C,0x0F,0x07,0x00,0x00},/*"p",79*/
{0x00,0x00,0x80,0xC0,0xE0,0x60,0x60,0xC0,0xE0,0xE0,0x60,0x00,0x00,0x00,0x07,0x0F,0x1C,0x18,0xD8,0xCC,0xFF,0xFF,0xC0,0x00},/*"q",80*/
{0x00,0x00,0x60,0x60,0xE0,0xE0,0xC0,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x18,0x18,0x1F,0x1F,0x18,0x18,0x18,0x00,0x00,0x00},/*"r",81*/
{0x00,0x00,0xC0,0xE0,0x60,0x60,0x60,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x1D,0x1D,0x1B,0x1B,0x1B,0x1E,0x0E,0x00,0x00,0x00},/*"s",82*/
{0x00,0x00,0x60,0x60,0xFC,0xFC,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x1F,0x18,0x18,0x18,0x0C,0x00,0x00},/*"t",83*/
{0x00,0x60,0xE0,0xE0,0x00,0x00,0x00,0x60,0xE0,0xE0,0x00,0x00,0x00,0x00,0x0F,0x1F,0x18,0x18,0x18,0x0C,0x1F,0x1F,0x18,0x00},/*"u",84*/
{0x00,0x60,0xE0,0xE0,0x60,0x00,0x60,0xE0,0xE0,0x60,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x18,0x1F,0x07,0x00,0x00,0x00,0x00},/*"v",85*/
{0x60,0xE0,0xE0,0x60,0x00,0x80,0x00,0x60,0xE0,0xE0,0x60,0x00,0x00,0x01,0x1F,0x1E,0x07,0x03,0x07,0x1E,0x1F,0x01,0x00,0x00},/*"w",86*/
{0x00,0x00,0x60,0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x60,0x00,0x00,0x00,0x00,0x18,0x1C,0x1F,0x03,0x03,0x1F,0x1C,0x18,0x00,0x00},/*"x",87*/
{0x00,0x60,0xE0,0xE0,0x60,0x00,0x00,0x60,0xE0,0xE0,0x60,0x00,0x00,0xC0,0xC0,0xC1,0xE7,0xFE,0xDC,0xC7,0x03,0x00,0x00,0x00},/*"y",88*/
{0x00,0x00,0xE0,0xE0,0x60,0x60,0x60,0xE0,0xE0,0x60,0x00,0x00,0x00,0x00,0x18,0x1C,0x1E,0x1B,0x1B,0x19,0x1C,0x1C,0x00,0x00},/*"z",89*/
{0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x3F,0x7E,0x60,0x00,0x00,0x00,0x00},/*"{",90*/
{0x00,0x00,0x00,0x00,0x00,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00},/*"|",91*/
{0x00,0x00,0x00,0x00,0x0C,0xFC,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x7E,0x3F,0x01,0x00,0x00,0x00,0x00},/*"}",92*/
{0x00,0x00,0x80,0xC0,0xC0,0xC0,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x01,0x03,0x03,0x03,0x01,0x00,0x00},/*"~",93*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",94*/
};

static const unsigned char blank_block PROGMEM = 0x00;
