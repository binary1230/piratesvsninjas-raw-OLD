#ifndef Test_Rect_H 
#define Test_Rect_H 

#include <cppunit/extensions/HelperMacros.h>
#include <stdio.h>
#include "rect.h"

class Test_Rect : public CppUnit::TestFixture {
				CPPUNIT_TEST_SUITE( Test_Rect ); 
				CPPUNIT_TEST( testGetSet ); 
				CPPUNIT_TEST( testConstructors );
				CPPUNIT_TEST( testClear );
				CPPUNIT_TEST( testOperatorEquals ); 
				CPPUNIT_TEST( testOperatorEqualsFuzzy ); 
				CPPUNIT_TEST( testOverlap );
				CPPUNIT_TEST( testOverlap2 );
				CPPUNIT_TEST( testDoesNotOverlap );
				CPPUNIT_TEST( testProject );
				CPPUNIT_TEST_SUITE_END(); 
				
			public: 
				void setUp(); 
				void tearDown(); 
				
				void testGetSet(); 
				void testClear();
				void testConstructors();
				void testOperatorEquals(); 
				void testOperatorEqualsFuzzy();
				void testDoesNotOverlap();
				void testOverlap();
				void testOverlap2();
				void testProject();

				int count;
				float *testing_set;
			}; 

#endif // Test_Vector2D_H 
