<?php

function format_control_tips_page($format) {
  $output = theme('filter_tips', array('tips' => _filter_tips($format->format, TRUE), 'long' => TRUE));
  if (isset($_POST['js']) && module_exists('ctools')) {
    ctools_include('modal');
    ctools_modal_render('Formatting Guidelines', $output);
  } else {
    return $output;
  }
}