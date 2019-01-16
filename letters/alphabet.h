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

const int l_lower_far_left  = 9;
const int l_lower_mid_left  = 10;
const int l_lower_middle    = 11;
const int l_lower_mid_right = 12;
const int l_lower_far_right = 13;

const int l_all_middle      = 14;
const int l_all_left        = 15;
const int l_all_right       = 16;
const int l_vertical_center = 17;

typedef std::initializer_list<const int> segment_lookup_t;
const std::map<char, const segment_lookup_t> letter_lut = {
    {' ', {}}, // space doesnt display anything

    {'A', {l_top, l_all_middle, l_all_left, l_all_right}},
    {'a', {l_top, l_all_middle, l_all_left, l_all_right}},

    {'B', {l_top, l_vertical_center, l_all_right, l_middle_right, l_bottom}},
    {'b', {l_top, l_vertical_center, l_all_right, l_middle_right, l_bottom}},
    
    {'C', {l_top, l_all_left, l_bottom}},
    {'c', {l_top, l_all_left, l_bottom}},
    
    {'D', {l_top, l_all_right, l_vertical_center, l_bottom}},
    {'d', {l_top, l_all_right, l_vertical_center, l_bottom}},

    {'E', {l_top, l_all_middle, l_bottom, l_all_left}},
    {'e', {l_top, l_all_middle, l_bottom, l_all_left}},

    {'F', {l_top, l_middle_left, l_all_left}},
    {'f', {l_top, l_middle_left, l_all_left}},

    {'G', {l_top, l_all_left, l_bottom, l_lower_far_right, l_middle_right}},
    {'g', {l_top, l_all_left, l_bottom, l_lower_far_right, l_middle_right}},

    {'H', {l_all_left, l_all_middle, l_all_right}},
    {'h', {l_all_left, l_all_middle, l_all_right}},

    {'I', {l_top, l_bottom, l_vertical_center}},
    {'i', {l_top, l_bottom, l_vertical_center}},

    {'J', {l_top, l_vertical_center, l_bottom, l_lower_far_left}},
    {'j', {l_top, l_vertical_center, l_bottom, l_lower_far_left}},

    {'K', {l_all_left, l_upper_mid_right, l_lower_mid_right, l_middle_left}},
    {'k', {l_all_left, l_upper_mid_right, l_lower_mid_right, l_middle_left}},

    {'L', {l_all_left, l_bottom}},
    {'l', {l_all_left, l_bottom}},

    {'M', {l_all_left, l_upper_mid_left, l_upper_mid_right, l_all_right}},
    {'m', {l_all_left, l_upper_mid_left, l_upper_mid_right, l_all_right}},

    {'N', {l_all_left, l_all_right, l_upper_mid_left, l_lower_mid_right}},
    {'n', {l_all_left, l_all_right, l_upper_mid_left, l_lower_mid_right}},

    {'O', {l_top, l_all_left, l_bottom, l_all_right}},
    {'o', {l_top, l_all_left, l_bottom, l_all_right}},

    {'P', {l_top, l_all_left, l_upper_far_right, l_all_middle}},
    {'p', {l_top, l_all_left, l_upper_far_right, l_all_middle}},

    {'Q', {l_top, l_all_right, l_upper_far_left, l_all_middle}},
    {'q', {l_top, l_all_right, l_upper_far_left, l_all_middle}},

    {'R', {l_all_left, l_top, l_upper_far_right, l_all_middle, l_lower_mid_right}},
    {'r', {l_all_left, l_top, l_upper_far_right, l_all_middle, l_lower_mid_right}},

    {'S', {l_top, l_upper_far_left, l_all_middle, l_lower_far_right, l_bottom}},
    {'s', {l_top, l_upper_far_left, l_all_middle, l_lower_far_right, l_bottom}},

    {'T', {l_top, l_vertical_center}},
    {'t', {l_top, l_vertical_center}},

    {'U', {l_all_left, l_all_right, l_bottom}},
    {'u', {l_all_left, l_all_right, l_bottom}},

    {'V', {l_all_right, l_lower_mid_right, l_upper_mid_left}},
    {'v', {l_all_right, l_lower_mid_right, l_upper_mid_left}},
    
    {'W', {l_all_left, l_all_right, l_lower_mid_left, l_lower_mid_right}},
    {'w', {l_all_left, l_all_right, l_lower_mid_left, l_lower_mid_right}},

    {'X', {l_upper_mid_left, l_upper_mid_right, l_lower_mid_left, l_lower_mid_right}},
    {'x', {l_upper_mid_left, l_upper_mid_right, l_lower_mid_left, l_lower_mid_right}},

    {'Y', {l_lower_middle, l_upper_mid_left, l_upper_mid_right}},
    {'y', {l_lower_middle, l_upper_mid_left, l_upper_mid_right}},

    {'Z', {l_top, l_bottom, l_upper_mid_right, l_lower_mid_left}},
    {'z', {l_top, l_bottom, l_upper_mid_right, l_lower_mid_left}},

    // all of the numeric characters
    {'0', {l_top, l_bottom, l_all_left, l_all_right}},
    {'1', {l_all_right}},
    {'2', {l_top, l_upper_far_right, l_all_middle, l_lower_far_left, l_bottom}},
    {'3', {l_top, l_upper_far_right, l_all_middle, l_lower_far_right, l_bottom}},
    {'4', {l_upper_far_left, l_all_middle, l_all_right}},
    {'5', {l_top, l_upper_far_left, l_all_middle, l_lower_far_right, l_bottom}},
    {'6', {l_top, l_all_left, l_all_middle, l_lower_far_right, l_bottom}},
    {'7', {l_top, l_all_right}},
    {'8', {l_top, l_all_left, l_all_middle, l_all_right, l_bottom}},
    {'9', {l_top, l_upper_far_left, l_all_middle, l_all_right}},
};
