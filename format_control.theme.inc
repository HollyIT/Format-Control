<?php

/**
 * @file
 * Enhances Drupal's core input format settings.
 */
function theme_format_control_filter_table(&$variables) {
  $form = $variables['form'];
  $rows = array();
  $output = '';
  if (is_array($form)) {
    $form['#sorted'] = FALSE;
    foreach (element_children($form, TRUE) as $name) {
      
      $form[$name]['weight']['#attributes']['class'][] = 'format-order-weight';
      $rows[] = array(
        'data' => array(
          drupal_render($form[$name]['name']),
          drupal_render($form[$name]['weight']),
          drupal_render($form[$name]['disable']),
        ),
        'class' => array('draggable'),
      );
    }
  }

  $header = array(
    t('Format'),
    t('Weight'),
    t('Disable')
  );

  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'format-order')));
  drupal_add_tabledrag('format-order', 'order', 'sibling', 'format-order-weight', NULL, NULL, TRUE);

  return $output;
}
