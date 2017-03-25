// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_INTERNAL_AT_HH
#define TAOCPP_PEGTL_INCLUDE_INTERNAL_AT_HH

#include "../config.hh"

#include "skip_control.hh"
#include "trivial.hh"
#include "rule_conjunction.hh"

#include "../apply_mode.hh"
#include "../rewind_mode.hh"

#include "../analysis/generic.hh"

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      namespace internal
      {
         template< typename ... Rules > struct at;

         template< typename ... Rules >
         struct skip_control< at< Rules ... > > : std::true_type {};

         template<>
         struct at<>
               : trivial< true > {};

         template< typename ... Rules >
         struct at
         {
            using analyze_t = analysis::generic< analysis::rule_type::OPT, Rules ... >;

            template< apply_mode, rewind_mode, template< typename ... > class Action, template< typename ... > class Control, typename Input, typename ... States >
            static bool match( Input & in, States && ... st )
            {
               const auto m = in.template mark< rewind_mode::REQUIRED >();
               return rule_conjunction< Rules ... >::template match< apply_mode::NOTHING, rewind_mode::ACTIVE, Action, Control >( in, st ... );
            }
         };

      } // namespace internal

   } // namespace TAOCPP_PEGTL_NAMESPACE

} // namespace tao

#endif
