// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2017-2019, The Iridium developers
// Copyright (c) 2019, The Goodness Project
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#include "gtest/gtest.h"
#include "Globals.h"

#include <Logging/ConsoleLogger.h>

Logging::ConsoleLogger logger;
System::Dispatcher globalSystem;
CryptoNote::Currency currency = CryptoNote::CurrencyBuilder(logger).testnet(true).currency();
Tests::Common::BaseFunctionalTestsConfig config;


namespace po = boost::program_options;

int main(int argc, char** argv) {
  CLogger::Instance().init(CLogger::DEBUG);

  po::options_description desc;
  po::variables_map vm;
  
  config.init(desc);
  po::store(po::command_line_parser(argc, argv).options(desc).allow_unregistered().run(), vm);
  po::notify(vm);
  config.handleCommandLine(vm);

  try {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

  } catch (std::exception& ex) {
    LOG_ERROR("Fatal error: " + std::string(ex.what()));
    return 1;
  }
}
