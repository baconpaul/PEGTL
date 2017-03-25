// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_INTERNAL_DEMANGLE_CXXABI_HH
#define TAOCPP_PEGTL_INCLUDE_INTERNAL_DEMANGLE_CXXABI_HH

#include <string>
#include <memory>
#include <cstdlib>
#include <cxxabi.h>

#include "../config.hh"

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      namespace internal
      {
         inline std::string demangle( const char * symbol )
         {
            const std::unique_ptr< char, decltype( & std::free ) > demangled( abi::__cxa_demangle( symbol, nullptr, nullptr, nullptr ), & std::free );
            return demangled ? demangled.get() : symbol;
         }

      } // namespace internal

   } // namespace TAOCPP_PEGTL_NAMESPACE

} // namespace tao

#endif
