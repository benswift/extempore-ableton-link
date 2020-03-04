#include "ableton/Link.hpp"

extern "C" {

  ableton::Link* link_new(double bpm) {
	return new ableton::Link(bpm);
  }

}
