///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Lab 07d - Animal Farm 1 - EE 205 - Spr 2022
///
/// @file reportCats.c
/// @version 1.0
///
/// This modules finds and prints cats in the catabase.
///
/// @author Bodie Collins <Bodie@hawaii.edu>
/// @date   19_Feb_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>  // For strncmp
#include <assert.h>  // For the assert function

#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"


bool printCat( const size_t index ) {
    if( !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false ;
    }

    printf( "cat index = [%lu]  name=[%s]  gender=[%s]  breed=[%s]  isFixed=[%d]  weight=[%f]  color1=[%s]  color2=[%s]  license=[%llu]\n"
            ,index
            ,cats[index].name
            ,genderName( cats[index].gender )
            ,breedName( cats[index].breed )
            ,cats[index].isFixed
            ,cats[index].weight
            ,colorName( cats[index].collarColor1 )
            ,colorName( cats[index].collarColor2 )
            ,cats[index].license
    ) ;

    return true;
}


void printAllCats() {
#ifdef DEBUG
    printf( "numCats = [%lu]\n", numCats ) ;
#endif

    for( size_t i = 0 ; i < numCats ; i++ ) {
        printCat( i ) ;
    }
}


size_t findCatByName( const char* name ) {
    if( name == NULL ) {
        return BAD_CAT ;  // Silently return... no cat found
    }

    for( size_t i = 0 ; i < numCats ; i++ ) {
        if( strncmp( name, cats[i].name, MAX_CAT_NAME ) == 0 ) {  // Found a match!
            return i ;
        }
    }

    return BAD_CAT ; // No name matched
}


size_t findCatByCollars( const enum Color collarColor1, const enum Color collarColor2 ) {
    for( size_t i = 0 ; i < numCats ; i++ ) {
        if( cats[i].collarColor1 == collarColor1 && cats[i].collarColor2 == collarColor2 ) {  // Found a match!
            return i ;
        }
    }

    return BAD_CAT ; // No cat matched
}


size_t findCatByLicense( unsigned long long license ) {
    for( size_t i = 0 ; i < numCats ; i++ ) {
        if( cats[i].license == license ) {  // Found a match!
            return i ;
        }
    }

    return BAD_CAT ; // No cat matched
}


const char* genderName( const enum Gender gender ) {
    switch( gender ) {
        case UNKNOWN_GENDER: return "Unknown" ;
        case MALE:           return "Male"    ;
        case FEMALE:         return "Female"  ;
    }

    assert( false ) ; // We should never get here
    return NULL;
}


const char* breedName( const enum Breed breed ) {
    switch( breed ) {
        case UNKNOWN_BREED: return "Unknown"    ;
        case MAINE_COON   : return "Maine Coon" ;
        case MANX         : return "Manx"       ;
        case SHORTHAIR    : return "Shorthair"  ;
        case PERSIAN      : return "Persian"    ;
        case SPHYNX       : return "Sphynx"     ;
    }
    assert( false ) ; // We should never get here
    return NULL;
}


const char* colorName ( const enum Color color ) {
    switch( color ) {
        case BLACK: return "Black" ;
        case WHITE: return "White" ;
        case RED  : return "Red"   ;
        case BLUE : return "Blue"  ;
        case GREEN: return "Green" ;
        case PINK : return "Pink"  ;
    }
    assert( false ) ; // We should never get here
    return NULL;
}