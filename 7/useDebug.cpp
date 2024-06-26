/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/ 

#include "Version_test.h"

#include <iostream>
using std::cerr; using std::endl;

#include "Debug.h"
#include "Version_test.h"

// only implementation for the Debug classes are definitions
// for static members named enable
#ifdef CONSTEXPR_CTORS
constexpr Debug HW_Subsystem::enable;
constexpr Debug IO_Subsystem::enable;
#else
const Debug HW_Subsystem::enable(true, false, false);
const Debug IO_Subsystem::enable(true, false, true);
#endif

int main()
{
#ifdef CONSTEXPR_VARS
	constexpr Debug io_sub(false, true, false);  // debugging IO    
#else
	const     Debug io_sub(false, true, false);  // debugging IO    
#endif
	if (io_sub.any())  // equivalent to if(true)
		cerr << "print appropriate error messages" << endl;

#ifdef CONSTEXPR_VARS
	constexpr Debug prod(false); // no debugging during production
#else
	const     Debug prod(false); // no debugging during production
#endif
	if (prod.any())    // equivalent to if(false)
		cerr << "print an error message" << endl;

	IO_Subsystem ioErrs;        // by default, don't print any debugging
	// no debugging here
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 3" << endl;
	ioErrs.set_debug(true);     // turn on debugging
	if (ioErrs.default_debug()) // if (false || debug.any())
		cerr << "print message 4" << endl;
	ioErrs.set_debug(false);    // okay, debugging section complete

	HW_Subsystem hw;
	hw.set_debug(true);
	if (ioErrs.default_debug() || hw.default_debug()) // if (false || debug.any())
		cerr << "print message 5" << endl;
}
