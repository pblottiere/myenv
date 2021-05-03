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

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Colors
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" blue : 74
" dark dark grey : 233
" background : 235
" light grey : 249

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Undetermined
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
hi Constant       ctermfg=249
hi Cursor         ctermfg=74
hi iCursor        ctermfg=74
hi Debug          ctermfg=74
hi Define         ctermfg=green
hi Delimiter      ctermfg=green

hi DiffAdd        ctermfg=255
hi DiffChange     ctermfg=255
hi DiffDelete     ctermfg=255
hi DiffText       ctermfg=255

hi Directory      ctermfg=green cterm=bold
hi Error          ctermfg=green
hi ErrorMsg       ctermfg=green
hi Exception      ctermfg=green
hi FoldColumn     ctermfg=235 ctermbg=235

hi Folded         ctermfg=242 ctermbg=none
hi Ignore         ctermfg=green
hi IncSearch      ctermfg=green

hi Keyword        ctermfg=green

hi SpecialKey     ctermfg=green

hi MatchParen     ctermfg=green
hi ModeMsg        ctermfg=green
hi MoreMsg        ctermfg=green

" complete menu
hi Pmenu          ctermfg=red
hi PmenuSel       ctermfg=red
hi PmenuSbar      ctermfg=red
hi PmenuThumb     ctermfg=red

hi Question       ctermfg=red
hi Search         ctermfg=red

" marks
hi SignColumn     ctermfg=74
hi SpecialChar    ctermfg=74
hi SpecialComment ctermfg=74
if has("spell")
    hi SpellBad   ctermfg=74
    hi SpellCap   ctermfg=74
    hi SpellLocal ctermfg=74
    hi SpellRare  ctermfg=74
endif

hi StatusLine     ctermfg=red
hi StatusLineNC   ctermfg=74

hi Tag            ctermfg=red
hi Title          ctermfg=74
hi Todo           ctermfg=242 ctermbg=none

hi Underlined     ctermfg=234

hi VertSplit      ctermfg=234
hi VisualNOS      ctermfg=74
hi Visual         ctermfg=235
hi WarningMsg     ctermfg=74
hi WildMenu       ctermfg=74

hi TabLineFill    ctermfg=74
hi TabLine        ctermfg=74

hi Normal         ctermfg=249 ctermbg=none cterm=None
hi Comment        ctermfg=242 cterm=italic
hi CursorLine     ctermfg=none
hi CursorLineNr   ctermfg=none
hi CursorColumn   ctermfg=none
hi ColorColumn    ctermbg=232
hi LineNr         ctermfg=74
hi NonText        ctermfg=none
hi SpecialKey     ctermfg=none

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" language
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" yml identifier
hi Identifier     ctermfg=74  cterm=bold

" C++: for
hi Repeat          ctermfg=249

" C++: functions
hi Function     ctermfg=74      cterm=italic

" C++: float
hi Float    ctermfg=249

" C++: "XXX", <XXX>
hi String       ctermfg=249     cterm=italic

" C++: number
hi Number       ctermfg=249

" C++: 'X'
hi Character        ctermfg=249     cterm=italic

" C++: true, false
hi Boolean         ctermfg=249

" C++: if/else, switch
hi Conditional     ctermfg=249

" C++: case
hi Label           ctermfg=74

" C++: #define
hi Macro           ctermfg=74

" C++: const_iterator, unique_ptr,
" QGIS: extent
hi Typedef         ctermfg=249

" C++: auto, int, bool, void, double, ...
hi Type            ctermfg=249

" C++: const,
hi StorageClass    ctermfg=249

" C++: typedef
hi Structure       ctermfg=249

" C++: #if/#endif
hi PreCondit       ctermfg=74

" C++: #include
hi PreProc         ctermfg=74

" C++: new, this, delete, return, break, continue, static_cast
hi Statement       ctermfg=249

" Python: not, in
hi Operator       ctermfg=249

" Python: '\n'
hi Special        ctermfg=249

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" syntastic
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
hi SyntasticErrorLine ctermbg=none ctermfg=none
hi SyntasticWarningLine ctermbg=none ctermfg=none
hi SyntasticStyleErrorLine ctermbg=none ctermfg=none
hi SyntasticStyleWarningLine ctermbg=none ctermfg=none

hi SyntasticErrorSign ctermbg=none ctermfg=1
hi SyntasticWarningSign ctermbg=none ctermfg=172
hi SyntasticStyleErrorSign ctermbg=none ctermfg=172
hi SyntasticStyleWarningSign ctermbg=none ctermfg=172

hi SignColumn ctermbg=none

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" YCM
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
hi Pmenu ctermfg=74 ctermbg=233 guifg=#ffffff guibg=#0000ff

" Must be at the end, because of ctermbg=234 bug.
" https://groups.google.com/forum/#!msg/vim_dev/afPqwAFNdrU/nqh6tOM87QUJ
set background=dark
