
///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Lab 07d - Animal Farm 1 - EE 205 - Spr 2022
///
/// @file updateCats.c
/// @version 1.0
///
/// This modules updates cats in the catabase.
///
/// @author Bodie Collins <bodie@hawaii.edu>
/// @date   19_Feb_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>  // For memset and strncpy
#include <assert.h>

#include "config.h"
#include "updateCats.h"
#include "reportCats.h"

#define CHECK_INDEX( index )    if( !isIndexValid( index ) ) {                                              \
                                           fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;  \
                                           return false ;                                                           \
                                   }



bool updateCatName( const size_t index, const char* name ) {
    CHECK_INDEX( index )

    if( !isNameValid( name ) ) {  // Is the name too long, too short or NULL
        return false ;
    }

    if( findCatByName( name ) != BAD_CAT ) { // Does the name already exist in the database
        /// @todo Print error message
        return false;
    }

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    memset( cats[index].name, 0, MAX_CAT_NAME ) ;  // Zero out the old cat's name
    strncpy( cats[index].name, name, MAX_CAT_NAME-1 ) ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it
    return true ;
}


bool fixCat( const size_t index ) {
    CHECK_INDEX( index )

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    cats[index].isFixed = true ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it

    return true ;
}


bool updateCatWeight( const size_t index, const float weight ) {
    CHECK_INDEX( index )

    if( isWeightValid( weight ) == false ) {
        return false ;
    }

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    cats[index].weight = weight ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it

    return true ;
}


bool updateCatCollar1( const size_t index, const enum Color color ) {
    CHECK_INDEX( index )

    if( areCatCollarsValid( color, cats[index].collarColor2 ) == false ) {
        return false ;
    }

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    cats[index].collarColor1 = color ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it

    return true ;
}


bool updateCatCollar2( const size_t index, const enum Color color ) {
    CHECK_INDEX( index )

    if( areCatCollarsValid( cats[index].collarColor1, color ) == false ) {
        return false ;
    }

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    cats[index].collarColor2 = color ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it

    return true ;
}


bool updateLicense( const size_t index, const unsigned long long license ) {
    CHECK_INDEX( index )

    if( findCatByLicense( license ) != BAD_CAT ) {
        /// @todo Print error message
        return false ;
    }

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // before we tinker with it

    // Do the deed
    cats[index].license = license ;

    assert( validateDatabase() == true ) ;  // Verify database is healthy
    // after we tinker with it

    return true ;
}