#pragma once

#include "quantum.h"

// Custom keycodes for German characters used in this keymap.
// These keycodes are handled in process_record_user in keymap.c

enum custom_keycodes {
    DE_AE = SAFE_RANGE, // ä / Ä
    DE_OE,              // ö / Ö
    DE_UE,              // ü / Ü
    DE_SS,              // ß
};
