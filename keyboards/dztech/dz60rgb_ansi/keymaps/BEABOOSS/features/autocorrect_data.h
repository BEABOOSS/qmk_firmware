#pragma once

// Autocorrection dictionary (23 entries):
//  
//   fasle    -> false
//   fitler   -> filter
//   flase    -> false
//   heigth   -> height
//   intput   -> input
//   lenght   -> length
//   listner  -> listener
//   ouptut   -> output
//   ouput    -> output
//   recieve  -> receive
//   reuslt   -> result
//   retrun   -> return
//   retun    -> return
//   reutrn   -> return
//   singed   -> signed
//   swithc   -> switch
//   swtich   -> switch
//   thresold -> threshold
//   udpate   -> update
//   widht    -> width
//   virutal  -> virtual
//   vitual   -> virtual
//   yeild    -> yield

#define AUTOCORRECT_MIN_LENGTH 5 // "fasle"
#define AUTOCORRECT_MAX_LENGTH 8 // "thresold"
#define DICTIONARY_SIZE 349

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x46, 0x19, 0x00, 0x07, 0x23, 0x00, 0x08, 0x51, 0x00, 0x0B, 0x89, 0x00, 0x0F, 0xA4, 0x00, 0x11,
    0xC3, 0x00, 0x15, 0xEC, 0x00, 0x17, 0x0A, 0x01, 0x00, 0x0B, 0x17, 0x0C, 0x1A, 0x16, 0x00, 0x81,
    0x63, 0x68, 0x00, 0x48, 0x2A, 0x00, 0x0F, 0x35, 0x00, 0x00, 0x0A, 0x11, 0x0C, 0x16, 0x00, 0x83,
    0x67, 0x6E, 0x65, 0x64, 0x00, 0x4C, 0x3C, 0x00, 0x12, 0x45, 0x00, 0x00, 0x08, 0x1C, 0x00, 0x83,
    0x69, 0x65, 0x6C, 0x64, 0x00, 0x16, 0x08, 0x15, 0x0B, 0x17, 0x00, 0x82, 0x68, 0x6F, 0x6C, 0x64,
    0x00, 0x4F, 0x5E, 0x00, 0x16, 0x67, 0x00, 0x17, 0x71, 0x00, 0x19, 0x7D, 0x00, 0x00, 0x16, 0x04,
    0x09, 0x00, 0x82, 0x6C, 0x73, 0x65, 0x00, 0x04, 0x0F, 0x09, 0x00, 0x83, 0x61, 0x6C, 0x73, 0x65,
    0x00, 0x04, 0x13, 0x07, 0x18, 0x00, 0x84, 0x70, 0x64, 0x61, 0x74, 0x65, 0x00, 0x08, 0x0C, 0x06,
    0x08, 0x15, 0x00, 0x83, 0x65, 0x69, 0x76, 0x65, 0x00, 0x46, 0x90, 0x00, 0x17, 0x9B, 0x00, 0x00,
    0x0C, 0x17, 0x1A, 0x16, 0x00, 0x83, 0x69, 0x74, 0x63, 0x68, 0x00, 0x0A, 0x0C, 0x08, 0x0B, 0x00,
    0x81, 0x68, 0x74, 0x00, 0x04, 0x00, 0x57, 0xAD, 0x00, 0x18, 0xB8, 0x00, 0x00, 0x18, 0x15, 0x0C,
    0x19, 0x00, 0x83, 0x74, 0x75, 0x61, 0x6C, 0x00, 0x17, 0x0C, 0x19, 0x00, 0x83, 0x72, 0x74, 0x75,
    0x61, 0x6C, 0x00, 0x55, 0xCA, 0x00, 0x18, 0xD5, 0x00, 0x00, 0x17, 0x18, 0x08, 0x15, 0x00, 0x83,
    0x74, 0x75, 0x72, 0x6E, 0x00, 0x55, 0xDC, 0x00, 0x17, 0xE5, 0x00, 0x00, 0x17, 0x08, 0x15, 0x00,
    0x82, 0x75, 0x72, 0x6E, 0x00, 0x08, 0x15, 0x00, 0x80, 0x72, 0x6E, 0x00, 0x08, 0x00, 0x4F, 0xF5,
    0x00, 0x11, 0xFF, 0x00, 0x00, 0x17, 0x0C, 0x09, 0x00, 0x83, 0x6C, 0x74, 0x65, 0x72, 0x00, 0x17,
    0x16, 0x0C, 0x0F, 0x00, 0x82, 0x65, 0x6E, 0x65, 0x72, 0x00, 0x4B, 0x14, 0x01, 0x0F, 0x2A, 0x01,
    0x18, 0x35, 0x01, 0x00, 0x47, 0x1B, 0x01, 0x0A, 0x22, 0x01, 0x00, 0x0C, 0x1A, 0x00, 0x81, 0x74,
    0x68, 0x00, 0x11, 0x08, 0x0F, 0x00, 0x81, 0x74, 0x68, 0x00, 0x16, 0x18, 0x08, 0x15, 0x00, 0x83,
    0x73, 0x75, 0x6C, 0x74, 0x00, 0x53, 0x3C, 0x01, 0x17, 0x53, 0x01, 0x00, 0x57, 0x43, 0x01, 0x18,
    0x4B, 0x01, 0x00, 0x11, 0x0C, 0x00, 0x83, 0x70, 0x75, 0x74, 0x00, 0x12, 0x00, 0x82, 0x74, 0x70,
    0x75, 0x74, 0x00, 0x13, 0x18, 0x12, 0x00, 0x83, 0x74, 0x70, 0x75, 0x74, 0x00
};
