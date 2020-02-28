#include "ableton/Link.hpp"

extern "C" {

  Link* link_init(double bpm) {
	return new ableton::Link(bpm);
  }

}
