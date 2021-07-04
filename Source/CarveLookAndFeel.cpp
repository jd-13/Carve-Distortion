/*
 *    File:       CarveLookAndFeel.cpp
 *
 *    Version:    2.0.0
 *
 *    Created:    01/12/2018
 *
 *    This file is part of Carve.
 *
 *  Carve is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Carve is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Carve.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "CarveLookAndFeel.h"

CarveLookAndFeel::CarveLookAndFeel() {
    _regularFont = Font(Typeface::createSystemTypefaceFor(BinaryData::MontserratRegular_ttf,
                                                          BinaryData::MontserratRegular_ttfSize));
    _boldFont = Font(Typeface::createSystemTypefaceFor(BinaryData::MontserratBold_ttf,
                                                       BinaryData::MontserratBold_ttfSize));

    jassert(_regularFont.getTypefaceName().isNotEmpty());
    jassert(_boldFont.getTypefaceName().isNotEmpty());
}

Typeface::Ptr CarveLookAndFeel::getTypefaceForFont(const Font& font) {
    return font.isBold() ? _boldFont.getTypeface() : _regularFont.getTypeface();
}

