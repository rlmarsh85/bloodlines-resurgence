// examples/serialise.hpp
// Copyright (c) 2007 Ben Hanson (http://www.benhanson.net/)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file licence_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_LEXER_SERIALISE_HPP
#define BOOST_LEXER_SERIALISE_HPP

#include "state_machine.hpp"
#include <boost/serialization/vector.hpp>

namespace boost
{
namespace lexer
{
// IMPORTANT! This won't work if you don't enable RTTI!
template<typename CharT, class Archive>
void serialise (basic_state_machine<CharT> &sm_, Archive &ar_, unsigned int version_ = 1)
{
    ar_ & version_;
    ar_ & *sm_._lookup;
    ar_ & sm_._dfa_alphabet;
    ar_ & *sm_._dfa;
    ar_ & sm_._seen_BOL_assertion;
    ar_ & sm_._seen_EOL_assertion;
}
}
}

#endif
