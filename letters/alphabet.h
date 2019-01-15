#pragma once

// this file mostly contains a bunch of constant 
// data structures used to define a shitload of 
// letters in the alphabet. letters are (default)
// scaled to fit 10/line

#include <drawutils/drawutils.h>
#include <map>
#include <initializer_list>

const int l_top             = 0;
const int l_bottom          = 1;
const int l_middle_left     = 2;
const int l_middle_right    = 3;

const int l_upper_far_left  = 4;
const int l_upper_mid_left  = 5;
const int l_upper_middle    = 6;
const int l_upper_mid_right = 7;
const int l_upper_far_right = 8;

const int l_lower_far_left  = 4;
const int l_lower_mid_left  = 5;
const int l_lower_middle    = 6;
const int l_lower_mid_right = 7;
const int l_lower_far_right = 8;

const int l_all_middle      = 9;
const int l_all_left        = 10;
const int l_all_right       = 11;
const int l_vertical_center = 12;

typedef std::initializer_list<const int> segment_lookup_t;
const std::map<const char, const segment_lookup_t> letter_lut = {
    {' ', {}}, // space doesnt display anything
    {'A', {l_top, l_all_middle, l_all_left, l_all_right}},
    {'a', {l_top, l_all_middle, l_all_left, l_all_right}},
    {'B', {l_top, l_vertical_center, l_all_right, l_middle_right, l_bottom}},
    {'b', {l_top, l_vertical_center, l_all_right, l_middle_right, l_bottom}},
    {'C', {l_top, l_all_left, l_bottom}},
    {'c', {l_top, l_all_left, l_bottom}},
    {'D', {l_top, l_all_right, l_vertical_center, l_bottom}},
};
