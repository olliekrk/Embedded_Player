//
// Created by olliekrk on 24.11.2019.
//

#ifndef EMBEDDED_PLAYER_EFFECT_CONVERTER_H
#define EMBEDDED_PLAYER_EFFECT_CONVERTER_H

/* what needs to be done there:
 * - X-CUBE-AUDIO library provides ready audio-effects modules
 * - it excepts input to be wave format stereo input at 48kHz frequency
 * - that means we need: .wav file, 2 channels, 48_000 sampling rate
 *
 * useful modules:
 * - SRC441 module converts 44.1kHz to 48kHz
 * - SRC236 module converts any rate with a ratio of 2, 3, 6, 3/2, 1/2, 1/3, 1/6, or 2/3 to 48kHz
 * - GAM graphical equalizer module
 * - BAM bass manager module
 * */

#endif //EMBEDDED_PLAYER_EFFECT_CONVERTER_H
