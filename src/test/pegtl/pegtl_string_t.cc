// Copyright (c) 2015-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include <type_traits>

#include <tao/pegtl.hh>
#include <tao/pegtl/contrib/alphabet.hh>

namespace test
{
   // We only need to test that this compiles...

   struct foo : TAOCPP_PEGTL_STRING( "foo" ) {};
   struct foobar : tao::pegtl::sor< TAOCPP_PEGTL_STRING( "foo" ), TAOCPP_PEGTL_STRING( "bar" ) > {};

   static_assert( std::is_same< TAOCPP_PEGTL_STRING( "Hello" ), tao::pegtl::string< 'H', 'e', 'l', 'l', 'o' > >::value, "TAOCPP_PEGTL_STRING broken" );
   static_assert( ! std::is_same< TAOCPP_PEGTL_ISTRING( "Hello" ), tao::pegtl::string< 'H', 'e', 'l', 'l', 'o' > >::value, "TAOCPP_PEGTL_ISTRING broken" );
   static_assert( std::is_same< TAOCPP_PEGTL_ISTRING( "Hello" ), tao::pegtl::istring< 'H', 'e', 'l', 'l', 'o' > >::value, "TAOCPP_PEGTL_ISTRING broken" );

   // Strings may even contain embedded nulls

   static_assert( std::is_same< TAOCPP_PEGTL_STRING( "Hello, w\0rld!" ), tao::pegtl::string< 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 0, 'r', 'l', 'd', '!' > >::value, "TAOCPP_PEGTL_STRING broken" );

   // The strings currently have a maximum length of 512 characters.

   using namespace tao::pegtl::alphabet;
   static_assert( std::is_same< TAOCPP_PEGTL_STRING( "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" ),
                  tao::pegtl::string< a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z > >::value, "TAOCPP_PEGTL_STRING broken" );

} // namespace test

int main()
{
   return 0;
}
