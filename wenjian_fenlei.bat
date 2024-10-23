set source_dir=D:\datasel\自动气象站data
set dest_dir=D:\data_sel
mkdir %dest_dir%\A58265
mkdir %dest_dir%\H58265
mkdir %dest_dir%\Z58265
mkdir %dest_dir%\P58265
mkdir %dest_dir%\T58265
mkdir %dest_dir%\U58265
mkdir %dest_dir%\W58265
mkdir %dest_dir%\R58265
mkdir %dest_dir%\Txt
copy %source_dir%\A58265*.*  %dest_dir%\A58265\
copy %source_dir%\H58265*.*  %dest_dir%\H58265\
copy %source_dir%\Z58265*.*  %dest_dir%\Z58265\
copy %source_dir%\P58265*.*  %dest_dir%\P58265\
copy %source_dir%\T58265*.*  %dest_dir%\T58265\
copy %source_dir%\U58265*.*  %dest_dir%\U58265\
copy %source_dir%\W58265*.*  %dest_dir%\W58265\
copy %source_dir%\R58265*.*  %dest_dir%\R58265\


copy %source_dir%\FJ.TXT  %dest_dir%\Txt\
copy %source_dir%\HH.TXT  %dest_dir%\Txt\
copy %source_dir%\ZZ.TXT  %dest_dir%\Txt\

cls
tree 
cd    %dest_dir%
tree  %dest_dir%  >%dest_dir%\tree.txt
pause
