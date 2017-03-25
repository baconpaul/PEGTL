// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include "test.hh"

namespace tao
{
   namespace pegtl
   {
      void unit_test()
      {
         verify_analyze< bof >( __LINE__, __FILE__, false, false );

         verify_rule< bof >( __LINE__, __FILE__,  "", result_type::SUCCESS, 0 );

         for ( char i = 1; i < 127; ++i ) {
            const char s[] = { i, 0 };
            verify_rule< bof >( __LINE__, __FILE__, s, result_type::SUCCESS, 1 );
         }
         verify_rule< seq< alpha, bof > >( __LINE__, __FILE__, "a", result_type::LOCAL_FAILURE, 1 );
         verify_rule< seq< alpha, bof > >( __LINE__, __FILE__, "ab", result_type::LOCAL_FAILURE, 2 );
         verify_rule< seq< alpha, bof, alpha > >( __LINE__, __FILE__, "ab", result_type::LOCAL_FAILURE, 2 );
         verify_rule< seq< alpha, eol, bof > >( __LINE__, __FILE__,  "a\n", result_type::LOCAL_FAILURE, 2 );
         verify_rule< seq< alpha, eol, bof > >( __LINE__, __FILE__,  "a\nb", result_type::LOCAL_FAILURE, 3 );
      }

   } // namespace pegtl

} // namespace tao

#include "main.hh"
