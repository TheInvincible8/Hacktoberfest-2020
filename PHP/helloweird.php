<?php

$hello = 'hello';

$world = 'world';

$array = ['hello', ' world.'];

  if($hello == 'hello'){
    echo 'hello';
  }
  else echo 'goodbye';

  if($world == 'world'){
    echo ' world.';
  }
  else echo ' non-existent place.';
   
  echo '  ';

  foreach($array as $part){
    echo $part;
  }