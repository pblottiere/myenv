" Vim color file
"
" Author: Blottiere Paul
" https://github.com/pblottiere/myenv
"

hi clear

if version > 580
    hi clear
    if exists("syntax_on")
        syntax reset
    endif
endif
let g:colors_name="tergeist"

" blue : 74
" green : 77
" purple : 135
" orange : 209
" dark dark grey : 233
" dark grey : 239
" light grey : 249
" pink : 13

hi Boolean         guifg=#99CC99                        ctermfg=77
hi Character       guifg=#A8FF60                        ctermfg=77
hi Number          guifg=#99CC99                        ctermfg=77
hi String          guifg=#A8FF60                        ctermfg=77
hi Conditional     guifg=#92C5F7               gui=none ctermfg=209
hi Constant        guifg=#99CC99               gui=none ctermfg=77
hi Cursor          guifg=#000000 guibg=#F8F8F0          ctermfg=13
hi iCursor         guifg=#000000 guibg=#F8F8F0          ctermfg=13
hi Debug           guifg=#BCA3A3               gui=none ctermfg=13
hi Define          guifg=#66D9EF                        ctermfg=13
hi Delimiter       guifg=#8F8F8F                        ctermfg=13
hi DiffAdd                       guibg=#13354A
hi DiffChange      guifg=#89807D guibg=#4C4745
hi DiffDelete      guifg=#960050 guibg=#1E0010
hi DiffText                      guibg=#4C4745 gui=none

hi Directory       guifg=#AAAAAA               gui=none ctermfg=74 cterm=bold
hi Error           guifg=#A8FF60 guibg=#1E0010
hi ErrorMsg        guifg=#92C5F7 guibg=#232526 gui=none
hi Exception       guifg=#DAD085               gui=none
hi Float           guifg=#99CC99                        ctermfg=1
hi FoldColumn      guifg=#465457 guibg=#000000
hi Folded          guifg=#465457 guibg=#000000
hi Function        guifg=#DAD085                        ctermfg=74  cterm=none
hi Identifier      guifg=#B6B7EB                        ctermfg=74  cterm=bold
hi Ignore          guifg=#808080 guibg=bg
hi IncSearch       guifg=#C4BE89 guibg=#000000

hi Keyword         guifg=#92C5F7               gui=none ctermfg=135
hi Label           guifg=#A8FF60               gui=none ctermfg=135
hi Macro           guifg=#C4BE89               gui=none ctermfg=135
hi SpecialKey      guifg=#66D9EF               gui=none ctermfg=135

hi MatchParen      guifg=#B7B9B8 guibg=#444444 gui=none
hi ModeMsg         guifg=#A8FF60
hi MoreMsg         guifg=#A8FF60
hi Operator        guifg=#92C5F7                        ctermfg=209

" complete menu
hi Pmenu           guifg=#66D9EF guibg=#000000
hi PmenuSel                      guibg=#808080
hi PmenuSbar                     guibg=#080808
hi PmenuThumb      guifg=#66D9EF

hi PreCondit       guifg=#DAD085               gui=none ctermfg=135
hi PreProc         guifg=#DAD085                        ctermfg=135
hi Question        guifg=#66D9EF
hi Repeat          guifg=#92C5F7               gui=none
hi Search          guifg=#000000 guibg=#B4EC85
" marks
hi SignColumn      guifg=#DAD085 guibg=#232526
hi SpecialChar     guifg=#92C5F7               gui=none
hi SpecialComment  guifg=#7C7C7C               gui=none
hi Special         guifg=#66D9EF guibg=bg      gui=none
if has("spell")
    hi SpellBad    guisp=#FF0000 gui=undercurl
    hi SpellCap    guisp=#7070F0 gui=undercurl
    hi SpellLocal  guisp=#70F0F0 gui=undercurl
    hi SpellRare   guisp=#FFFFFF gui=undercurl
endif
hi Statement       guifg=#92C5F7               gui=none ctermfg=239
hi StatusLine      guifg=#455354 guibg=fg      gui=none ctermfg=234
hi StatusLineNC    guifg=#808080 guibg=#080808          ctermfg=234
hi StorageClass    guifg=#B6B7EB               gui=none ctermfg=77
hi Structure       guifg=#66D9EF                        ctermfg=77
hi Tag             guifg=#92C5F7               gui=none ctermfg=1
hi Title           guifg=#B6B7EB               gui=none
hi Todo            guifg=#FFFFFF guibg=bg      gui=none

hi Typedef         guifg=#66D9EF                        ctermfg=1
hi Type            guifg=#66D9EF               gui=none ctermfg=77
hi Underlined      guifg=#808080               gui=underline

hi VertSplit       guifg=#808080 guibg=#080808 ctermbg=none ctermfg=234
hi VisualNOS                     guibg=#403D3D
hi Visual                        guibg=#403D3D
hi WarningMsg      guifg=#FFFFFF guibg=#333333
hi WildMenu        guifg=#66D9EF guibg=#000000

hi TabLineFill     guifg=#1D1F21 guibg=#1D1F21
hi TabLine         guibg=#1D1F21 guifg=#808080 gui=none

hi Normal          guifg=#F8F8F2 guibg=#1D1F21          ctermfg=249 ctermbg=235
hi Comment         guifg=#FFFFFF                        ctermfg=242
hi CursorLine                    guibg=#293739
hi CursorLineNr    guifg=#B6B7EB               gui=none
hi CursorColumn                  guibg=#293739
hi ColorColumn                   guibg=#232526          ctermbg=232
hi LineNr          guifg=#465457 guibg=#232526          ctermfg=74 cterm=bold
hi NonText         guifg=#465457
hi SpecialKey      guifg=#465457

" syntastic
hi SyntasticErrorLine ctermbg=none ctermfg=none
hi SyntasticWarningLine ctermbg=none ctermfg=none
hi SyntasticStyleErrorLine ctermbg=none ctermfg=none
hi SyntasticStyleWarningLine ctermbg=none ctermfg=none

hi SyntasticErrorSign ctermbg=none ctermfg=1
hi SyntasticWarningSign ctermbg=none ctermfg=172
hi SyntasticStyleErrorSign ctermbg=none ctermfg=172
hi SyntasticStyleWarningSign ctermbg=none ctermfg=172

hi SignColumn ctermbg=none

" Must be at the end, because of ctermbg=234 bug.
" https://groups.google.com/forum/#!msg/vim_dev/afPqwAFNdrU/nqh6tOM87QUJ
set background=dark

