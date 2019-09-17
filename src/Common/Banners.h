#ifndef BANNERS_H
#define BANNERS_H
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// Ascii Arts by Thunderosa and Stevebrush - Remember the good old time
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#endif // BANNERS_H
#pragma once

#include <string>
namespace Common {
const std::string brightRed("\033[0;91m");
const std::string Red("\033[0;31m");
const std::string Green("\033[0;32m");
const std::string White("\033[1;37m");
const std::string reset("\033[0m");

const std::string windowsBanner =
"\n                                 				\n"
"                     1111    1    1   1111           \n"
"                    1        11   1   1  1           \n"
"                    1        1 1  1   11             \n"
"                    1  111   1  1 1     11           \n"
"                    1  1 1   1   11   1  1           \n"
"                     1111    1    1   1111           \n" 
;

const std::string WTBanner =
"\n                                 				\n"
"                     1111    1    1   1111           \n"
"                    1        11   1   1  1           \n"
"                    1        1 1  1   11             \n"
"                    1  111   1  1 1     11           \n"
"                    1  1 1   1   11   1  1           \n"
"                     1111    1    1   1111           \n" 
;

const std::string othersBanner = Red +
"\n                                 				\n"
"                     1111    1    1   1111           \n"
"                    1        11   1   1  1           \n"
"                    1        1 1  1   11             \n"
"                    1  111   1  1 1     11           \n"
"                    1  1 1   1   11   1  1           \n"
"                     1111    1    1   1111           \n" 
 + reset;

const std::string bannerText =
"          Your node is now synchronized with the Goodness network\n"
"             Type \"help\" for the list of available commands\n"
;

const std::string TBanner = brightRed +
"\n"
"--------------------------------------------------------------------------------\n"+ White +
"\n                                 				\n"
"                     1111    1    1   1111           \n"
"                    1        11   1   1  1           \n"
"                    1        1 1  1   11             \n"
"                    1  111   1  1 1     11           \n"
"                    1  1 1   1   11   1  1           \n"
"                     1111    1    1   1111           \n" +brightRed+
"--------------------------------------------------------------------------------\n"+Green
;

#ifdef _WIN32
//windows has non ansi chars ?
const std::string banner = WTBanner;
#else
const std::string banner = TBanner;
#endif
}
