   M S B A M L   `   `   `  ����N  JWpfKenoWithListView, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null9!clr-namespace:WpfKenoWithListViewWpfKenoWithListView  5   	   !    WpfKenoWithListView.Window1   5   	   \ XPresentationFramework, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      8x,http://schemas.microsoft.com/winfx/2006/xaml    5      -l!clr-namespace:WpfKenoWithListView    5   	     � Title$
  Keno��5      $	��600��6   $	��810��6    � 	Resources 5      ��%    5
      .��5      �  � RowDefinitions 5   
   �� 5      $��50 �6   �� 5       � ColumnDefinitions 5   
   �� 5      .+�5   
   �� -   5        $
��btn1��5      $��Загрузить��5      $��75��6%   $
��Left=�5      $��
12,12,0,15q�5       � ToolTip$7 1Нажмите для загрузки файла��5      �� 5   
   -   5        $
��img1��5      $��Center=�6   $��keno_logo300s.png��69   $��45��6T   $��90��6`   �� 5   
   -   5        $
��img2��5      $��Right=�6   $��002.gif��68   �� 5   
   -   5        $��StackPanel1��5      $��1��6(   $��Center=�65   .+�5      �� -   5        $��Listview��5      $��Center=�6(   $��Stretch=�6M   $	��510��6i   .@�6�   > �� View 5      �� 5       �� AllowsColumnReorder .  �� ColumnHeaderToolTip$# Информация Кено��6:   .P�5      �� $��Номер тиража��5   )    �� Width$	 100��6?   	 �� DisplayMemberBinding	 5   )   �� 
 �� Path$	
 Num�5   ?   �� 5      $��Дата тиража��5    )   $	 100��6>   	 5   )   �� $

 Date�5    >   �� 5!      $��Лототрон��5"   )   $ 60��6;   	 5!   )   �� $
 
Numberloto�5"   ;   �� 5#      $��К-т шаров��5$   )   $ 60��6<   	 5#   )   �� $
 Numberballs�5$   <   �� 5%      $'��!Выиграшные номера��5&   )   $	 458��6D   	 5%   )   �� $
 Number�5&   D   5'      5)      5*      5+      5,      