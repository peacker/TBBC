/**************************/
/* Emanuele Bellini, 2012 */
/**************************/

#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H


//#include "Bunny.h" //definition of the class Bunny

using namespace std ;
//using namespace Bunny<nb_msg,nb_key,nb_sbox,nround> ;

#include <stdint.h>

static uint8_t charToNum[128] = {
//funziona sul mio compilatore (LINUX) ??
// 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0
// 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 16
// 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 32
// 0,  1,  2,  3,  4,  5,  6, 7, 8, 9, 0, 0, 0, 0, 0, 0, // 48
// 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 64
// 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 80
// 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 96
// 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0

//Funziona sul compilatore di enrico (MAC) ??
 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0
 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 16
 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 32
 0,  1,  2,  3,  4,  5,  6, 7, 8, 9, 0, 0, 0, 0, 0, 0, // 48
 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 64
 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 80
 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 96
 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0

} ;

static char numToChar[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                              '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' } ;

//! Function to copy a string to a vector c of unsigned char.
/*!
  Note: it converts two string characters in one unsigned char.
- INPUT: a string s, and a pointer c[] to an array of characters that will be modified.
*/
void
stringToUcharB( string const & s, //!< string to be converted
               uint8_t * c       //!< converted number
             ) {
  for ( unsigned i = 0 ; i < s.length() ; i += 2 ){
    *c++ = (charToNum[s[i]&0x3F]<<4) | charToNum[s[i+1]&0x3F]  ;
  }
}

void stringToUchar (string s, unsigned char c[])
{
    unsigned d ;

    for (unsigned i = 0 ; i < s.length() ; i = i + 2){
        switch( s[i] ){
        case '0': d = 0 ;
            break ;
        case '1':  d = 1 * 16 ;
            break ;
        case '2':  d = 2 * 16 ;
            break ;
        case '3':  d = 3 * 16 ;
            break ;
        case '4':  d = 4 * 16 ;
            break ;
        case '5':  d = 5 * 16 ;
            break ;
        case '6':  d = 6 * 16 ;
            break ;
        case '7':  d = 7 * 16 ;
            break ;
        case '8':  d = 8 * 16 ;
            break ;
        case '9':  d = 9 * 16 ;
            break ;
        case 'a':  d = 10 * 16 ;
            break ;
        case 'b':  d = 11 * 16 ;
            break ;
        case 'c':  d = 12 * 16 ;
            break ;
        case 'd':  d = 13 * 16 ;
            break ;
        case 'e':  d = 14 * 16 ;
            break ;
        case 'f':  d = 15 * 16 ;
            break ;
      }
      switch( s[i+1] ){
        case '0': d = d + 0 ;
            break ;
        case '1':  d = d + 1 ;
            break ;
        case '2':  d = d + 2 ;
            break ;
        case '3':  d = d + 3 ;
            break ;
        case '4':  d = d + 4 ;
            break ;
        case '5':  d = d + 5 ;
            break ;
        case '6':  d = d + 6 ;
            break ;
        case '7':  d = d + 7 ;
            break ;
        case '8':  d = d + 8 ;
            break ;
        case '9':  d = d + 9 ;
            break ;
        case 'a':  d = d + 10 ;
            break ;
        case 'b':  d = d + 11 ;
            break ;
        case 'c':  d = d + 12 ;
            break ;
        case 'd':  d = d + 13 ;
            break ;
        case 'e':  d = d + 14 ;
            break ;
        case 'f':  d = d + 15 ;
            break ;
      }
        c[i / 2] = d ;
    }
}


//!To rotate a bitset to the left by m bits.
/*!
- INPUT: a bitset b, an integer m indicating how many bits to the left are requested to be shifted.

- OUTPUT: the bitset rotated.
*/
template <std::size_t N>
inline
std::bitset<N>
rotLeft(std::bitset<N>& b, unsigned m)
{
    b = b << m | b >> (N-m);
    return b ;
}


//!Moves nbits bits from position pos1 to pos2.
/*!
Note 1: Does not check for errors.

Note 2: Remember the rightmost bit has index zero.

- INPUT: a bitset b, two integer pos1 and pos2 indicating the positions to be exchanged, and an integer nbits indicating how many bits must be moved.

- OUTPUT: the new bitset.
*/
template <std::size_t N>
inline
std::bitset<N>
MoveBits(std::bitset<N>& b, unsigned pos1, unsigned pos2, unsigned nbits)
{
    bool tmp ;
    for (unsigned i = 0 ; i < nbits ; ++i){
        tmp = b[pos1+i] ;
        b[pos1+i] = b[pos2+i] ;
        b[pos2+i] = tmp ;
    }
    return b ;
}



//!To convert an hexadecimal string to a bitset<128> element.
/*!
- INPUT: a string s containing hexadecimal characters.

- OUTPUT: a bitset equivalent to the value in the string.
*/
inline
bitset<128> hexToBitset128(string c){
    //unsigned l = c.length() ;
    bitset <128> b ;
    string tmp ;
    for (unsigned i = 0 ; i < c.length() ; ++i){
      switch( c[i] ){
        case '0':  tmp.append("0000") ;
            break ;
        case '1':  tmp.append("0001") ;
            break ;
        case '2':  tmp.append("0010") ;
            break ;
        case '3':  tmp.append("0011") ;
            break ;
        case '4':  tmp.append("0100") ;
            break ;
        case '5':  tmp.append("0101") ;
            break ;
        case '6':  tmp.append("0110") ;
            break ;
        case '7':  tmp.append("0111") ;
            break ;
        case '8':  tmp.append("1000") ;
            break ;
        case '9':  tmp.append("1001") ;
            break ;
        case 'a':  tmp.append("1010") ;
            break ;
        case 'b':  tmp.append("1011") ;
            break ;
        case 'c':  tmp.append("1100") ;
            break ;
        case 'd':  tmp.append("1101") ;
            break ;
        case 'e':  tmp.append("1110") ;
            break ;
        case 'f':  tmp.append("1111") ;
            break ;
      }
    }
    b = bitset<128> (tmp) ;
    return b ;
}


//!To convert an hexadecimal string to a bitset<N> element.
/*!
- INPUT: a bitset b.

- OUTPUT: a string of hexadecimal characters equivalent to the value in the bitset.
*/
template <std::size_t N>
inline
string bitsetToHex(std::bitset<N> b){
  //string s = b.to_string();
  string hex ;

  int i = N%4 ;
    switch (i) {
    case 1: hex.append(1,numToChar[b[N-1]]) ; break ;
    case 2: hex.append(1,numToChar[b[N-2]+2*b[N-1]]) ; break ;
    case 3: hex.append(1,numToChar[b[N-3]+2*b[N-2]+4*b[N-1]]) ; break ;
  }
  for ( i = N-1; i >= 3 ; i -= 4 ){
    hex.append(1,numToChar[8*b[i] + 4*b[i-1] + 2*b[i-2] + b[i-3]]) ;
  }
  return hex ;
}


//!To convert a string of hexadecimal entries to T (works for T = bitset<N>).
/*!
- INPUT: a string s containing hexadecimal characters.

- OUTPUT: a bitset equivalent to the value in the string.
*/
template <typename T>
T
hexTo( string const & c ) {
  T b ;
  unsigned k = 4*c.length() ;
  for (unsigned i = 0 ; i < c.length() ; ++i ){
    k -= 4 ;
    unsigned n = charToNum[(int)c[i]] ;
    b[k+0] = n & 0x01 ; n >>= 1 ;
    b[k+1] = n & 0x01 ; n >>= 1 ;
    b[k+2] = n & 0x01 ; n >>= 1 ;
    b[k+3] = n & 0x01 ;
  }
  return b ;
}


/*!
To convert a bitset<128> element to an hexadecimal string.
*/
inline
string bitset128ToHex(bitset<128> b){
    string s = b.to_string();
    string hex ;
    bitset<4> oct ;
    for (unsigned i = 0 ; i < s.length() ; i = i + 4){
        oct[0] = b[s.length()-4-i] ;
        oct[1] = b[s.length()-3-i] ;
        oct[2] = b[s.length()-2-i] ;
        oct[3] = b[s.length()-1-i] ;
        if      (oct == bitset<4> (string("0000")) )  hex.append("0") ;
        else if (oct == bitset<4> (string("0001")) )  hex.append("1") ;
        else if (oct == bitset<4> (string("0010")) )  hex.append("2") ;
        else if (oct == bitset<4> (string("0011")) )  hex.append("3") ;
        else if (oct == bitset<4> (string("0100")) )  hex.append("4") ;
        else if (oct == bitset<4> (string("0101")) )  hex.append("5") ;
        else if (oct == bitset<4> (string("0110")) )  hex.append("6") ;
        else if (oct == bitset<4> (string("0111")) )  hex.append("7") ;
        else if (oct == bitset<4> (string("1000")) )  hex.append("8") ;
        else if (oct == bitset<4> (string("1001")) )  hex.append("9") ;
        else if (oct == bitset<4> (string("1010")) )  hex.append("a") ;
        else if (oct == bitset<4> (string("1011")) )  hex.append("b") ;
        else if (oct == bitset<4> (string("1100")) )  hex.append("c") ;
        else if (oct == bitset<4> (string("1101")) )  hex.append("d") ;
        else if (oct == bitset<4> (string("1110")) )  hex.append("e") ;
        else if (oct == bitset<4> (string("1111")) )  hex.append("f") ;
    }
    return hex ;
}

/*!
Function used to put an unsigned char into a string.

Ex: ucharToString(0x0a) returns "0a" as a string.
*/
template <class T>
inline std::string ucharToString (const T& t)
{
    std::stringstream ss ;
    std::string str ;
    ss << hex << (int)t ;
    if ( t <= 0x0f && t>=0x00 ) str = "0" ;
    str.append(ss.str()) ;

    return str ;
}

/*!
Multiplication in \f$ F_2^8 \f$.

- INPUT: two unsigned char a and b to be multipied.

- OUTPUT: the product of a * b in \f$ F_2^8 \f$ as an unsigned char.
*/
unsigned char gmul(unsigned char a, unsigned char b) {
    unsigned char p = 0;
    unsigned char counter;
    unsigned char hi_bit_set;
    for(counter = 0; counter < 8; counter++) {
        if((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if(hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}

/*!
Mix a single column.

- INPUT: unsigned char pointer to a vector of 4 bytes written as hexadecimal unsigned char.

- OUTPUT: the unsigned char vector modified.
*/
void gmix_column(unsigned char *r) {
        unsigned char a[4] ;
    unsigned char c ;
    for(c = 0 ; c < 4 ; ++c) {
        a[c] = r[c];
    }
    r[0] = gmul(a[0],2) ^ gmul(a[3],1) ^ gmul(a[2],1) ^ gmul(a[1],3) ;
    r[1] = gmul(a[1],2) ^ gmul(a[0],1) ^ gmul(a[3],1) ^ gmul(a[2],3) ;
    r[2] = gmul(a[2],2) ^ gmul(a[1],1) ^ gmul(a[0],1) ^ gmul(a[3],3) ;
    r[3] = gmul(a[3],2) ^ gmul(a[2],1) ^ gmul(a[1],1) ^ gmul(a[0],3) ;
}

/*!
Does the invers of mixing a single column.

- INPUT: unsigned char pointer to a vector of 4 bytes written as hexadecimal unsigned char.

- OUTPUT: the unsigned char vector modified.
*/
inline
void gmix_columnInv(unsigned char *r) {
        unsigned char a[4];
        unsigned char c;
        for(c=0;c<4;c++) {
                a[c] = r[c];
                }
        r[0] = gmul(a[0],14) ^ gmul(a[3],9) ^ gmul(a[2],13) ^ gmul(a[1],11);
        r[1] = gmul(a[1],14) ^ gmul(a[0],9) ^ gmul(a[3],13) ^ gmul(a[2],11);
        r[2] = gmul(a[2],14) ^ gmul(a[1],9) ^ gmul(a[0],13) ^ gmul(a[3],11);
        r[3] = gmul(a[3],14) ^ gmul(a[2],9) ^ gmul(a[1],13) ^ gmul(a[0],11);
}

#endif
