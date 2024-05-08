
#include "Graphics/GraphicsRenderer.hpp"
#include "Sound/SoundPlayer.hpp"

#include "Constants.hpp"

/* This file is recreating the logic of Bank 7 */


void ZeroOutNameTables(){
    // lda #$00
}

// This is the Startup 

void LevelRoutine00(){

    InitAPUChannels();
    ZeroOutNameTables();

    BossDefeatedFlag = false;
    
    /*
    jsr init_APU_channels
    jsr zero_out_nametables                   ; reset both nametables to zeroes
    lda #$06                                  ; load transition_screen_palettes (#$06th entry in short_text_pointer_table table bank 6)
    jsr load_bank_6_write_text_palette_to_mem ; load palette for level name and hi score screen into PPU
    ldy #$02
    jsr load_bank_number                      ; switch to bank 2
    lda CURRENT_LEVEL                         ; load current level
    asl                                       ; each level header is #$20 bytes so multiply by #20
    asl
    asl
    asl
    asl
    tay                                       ; y is CPU memory read offset
    ldx #$00                                  ; x is CPU memory write offset
    stx BOSS_DEFEATED_FLAG                    ; set flag to false
    stx LEVEL_END_PLAYERS_ALIVE               ; clear players alive after defeating boss heart flag
    */
}