   M S B A M L   `   `   `  ����`  \RibbonControlsLibrary, Version=3.5.31016.1, Culture=neutral, PublicKeyToken=31bf3856ad364e35tNclr-namespace:Microsoft.Windows.Controls.Ribbon;assembly=RibbonControlsLibrary!Microsoft.Windows.Controls.Ribbon  5   �    RibbonSample   RibbonSample.Window1   6   \ XPresentationFramework, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    60   8x,http://schemas.microsoft.com/winfx/2006/xaml    6r   ZrNclr-namespace:Microsoft.Windows.Controls.Ribbon;assembly=RibbonControlsLibrary    6�     � Title$  My First Ribbon Form��6   � 
ResizeMode$ CanResizeWithGrip=�6   � WindowStartupLocation$ CenterScreen=�6>   � Icon$ Images\app.png��6c  $	��600��6y  $	��800��6�  $	��300��6�  $	��400��6�   � 	Resources 5      5   /Microsoft.Windows.Controls.Ribbon.RibbonCommand   	QATButton   
LabelTitle   LabelDescription   ToolTipTitle   ToolTipDescription	   SmallImageSource
   LargeImageSource  	MenuItem1  	MenuItem2  	MenuItem3  	MenuItem4  HomeButton1  HomeButton2  HomeButton3  
MediaEject 	 MediaBackward 
 	MediaPlay  	MediaStop  MediaForward �� MergedDictionaries �� Source�� 5       5      �� 5   
   $A ;/RibbonControlsLibrary;component/Themes/Office2007Blue.xaml?�6   %�
  &	        &	 �     &	 �    &	 �    &	 \    &	 8    &	     &	 �    &	 �    &		 O    &	
     &	 �    &	 Y	      5      -   5        $ 
QAT Button��5   P   $! This is a sample QAT Button��6h   $ 
QAT Button��6�   $9 3This is a sample QAT Button, it doesn't do anything��6�   $	 Images\save.png��6�   $
 Images\save.png��6    5      -   5        $ Menu Item 1��5   P   $  This is a sample menu item��6i   $ Menu Item 1��6�   $  This is a sample menu item��6�   $	 Images\files.png��6�   $
 Images\files.png��6    5      -   5        $ Menu Item 2��5   P   $  This is a sample menu item��6i   $ Menu Item 2��6�   $  This is a sample menu item��6�   $	 Images\save.png��6�   $
 Images\save.png��6    5      -   5        $ Menu Item 3��5   P   $  This is a sample menu item��6i   $ Menu Item 3��6�   $  This is a sample menu item��6�   $	 Images\print.png��6�   $
 Images\print.png��6    5	      -   5        $ Menu Item 4��5	   P   $  This is a sample menu item��6i   $ Menu Item 4��6�   $  This is a sample menu item��6�   $	 Images\diagnostic.png��6�   $
 Images\diagnostic.png��6    5
      -   5        $ 
Calculator��5
   R   $ 
Calc This!��6j   $ 
Calculator��6�   $ Used to do math and stuff��6�   $	 Images\calculator.png��6�   $
 Images\calculator.png��6�     5      -   5        $ Calendar��5   R   $ Schedule This!��6h   $ Calendar��6�   $+ %Schedule and remind yourself of stuff��6�   $	 Images\calendar.png��6�   $
 Images\calendar.png��6    5      -   5        $ Computer��5   R   $ Format This!��6h   $ Computer��6�   $) #Where you store your naked pictures��6�   $	 Images\computer.png��6�   $
 Images\computer.png��6     5      -	   5        $ Eject��5   Q   $ Eject��6d   $ Eject��6}   $ Open the cup holder��6�   $	 Images\bt_eject.png��6�   $
 Images\bt_eject.png��6�     5      -
   5        $ Previous��5   T   $ Previous��6j   $ Previous��6�   $ Previous Tune��6�   $!	 Images\bt_skip_backward.png��6�   $!
 Images\bt_skip_backward.png��6�     5      -   5        $
 Play��5   P   $
 Play��6b   $
 Play��6z   $ 	Play Tune��6�   $	 Images\bt_play.png��6�   $
 Images\bt_play.png��6�     5      -   5        $
 Stop��5   P   $
 Stop��6b   $
 Stop��6z   $ Stop the music��6�   $	 Images\bt_stop.png��6�   $
 Images\bt_stop.png��6�     5      -   5        $
 Next��5   S   $
 Next��6e   $
 Next��6}   $ 	Next Tune��6�   $ 	 Images\bt_skip_forward.png��6�   $ 
 Images\bt_skip_forward.png��6�   5      .��5       ]� .+�5!      .   (Microsoft.Windows.Controls.Ribbon.Ribbon  -   5          Name$ 
mainRibbon��5!   A   $	��Top=�6      Title$ My First Ribbon Form��6$      QuickAccessToolBar 5"      @   :Microsoft.Windows.Controls.Ribbon.RibbonQuickAccessToolBar  5#   
   .@�5$      4   .Microsoft.Windows.Controls.Ribbon.RibbonButton  #��[  6     5%      #��[ 6      	Placement$ InCustomizeMenu=�6A   5&         ApplicationMenu 5(      =   7Microsoft.Windows.Controls.Ribbon.RibbonApplicationMenu  5)   
      Command 5*        5+      $	 Images\box.png��6   $
 Images\box.png��6@   .@�5-      A   ;Microsoft.Windows.Controls.Ribbon.RibbonApplicationMenuItem   m� Command# [ 6(   .@�5.      �� $��Item 1 in the list��6   �� 5/      $��Item 2 in the list��6   �� 50      $��Item 3 in the list��6   �� 51      $��Item 4 in the list��6   52        53      # [ 6(     54      # [ 6(     55      # [ 6(      RecentItemList 56      �� 57      $	��300��6   59         Tabs. 5;      1   +Microsoft.Windows.Controls.Ribbon.RibbonTab     Label$
 Home��6      Groups. 5<   
   3   -Microsoft.Windows.Controls.Ribbon.RibbonGroup     Command 5=        5>      $ Programs��6      GroupSizeDefinitions 5A      K	   EMicrosoft.Windows.Controls.Ribbon.RibbonGroupSizeDefinitionCollection	  A
   ;Microsoft.Windows.Controls.Ribbon.RibbonGroupSizeDefinition
  5B       
  ControlSizeDefinitions. 5C      C   =Microsoft.Windows.Controls.Ribbon.RibbonControlSizeDefinition     	ImageSize$ Large=�60      IsLabelVisible . 6B     5D      $ Large=�60    . 6B     5E      $ Large=�60    . 6B   5F      5G         Controls. 5I        #��[ 6     5J      #��[ 6     5K      #��[ 6   5L      5M   	     5N      $ Media��6   . 5O   
      5P        5Q      $ Media Controls��6   . 5S      :   4Microsoft.Windows.Controls.Ribbon.RibbonControlGroup     Controls. 5T        #��[ 6     5U      #��[	 6     5V      #��[
 6     5W      #��[ 6     5X      #��[ 6   5Y      5Z      5[   	   5\      �� 5]      $
��auto��6   $
��auto��6    . �5^      /� .T�5_   
   J� .*�6   .*�5`      �� $��http://www.renevo.com?�6   .�6:   RenEvo Software & Designs6Y   5a      5b   	   5c      5d      5e      