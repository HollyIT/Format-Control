<?php

/**
 * @file
 * Contains FAPI and theme functions for the format settings form.
 */
function format_control_admin_page() {
  $entities = entity_get_info();
  $output['table_title'] = array(
    '#markup' => '<h3>Define default formats per entity type</h3>'
  );
  foreach ($entities as $type => $entity) {
    $settings = variable_get('format_control_default_' . $type, array());
    $text = count($settings) ? 'Edit' : 'Add';
    $rows[] = array(
      $entity['label'],
      l($text, 'admin/config/content/formats/settings/defaults/' . $type)
    );
  }

  $output['table'] = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => array('Entity', 'Operatings')
  );


  return $output;
}


/**
 * FAPI form builder for default entity formats.
 *
 * @see format_control_menu()
 */
function format_control_default_settings_form($form, &$form_state, $entity) {

  $settings = variable_get('format_control_default_' . $entity, array());
  $settings = isset($settings['format_control']) ? $settings['format_control'] : array();
  $form['format_control'] = format_control_format_table($settings);

  $form['#entity'] = $entity;
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration')
  );
  if (isset($settings['formats'])) {
    $form['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete this default'),
      '#submit' => array('format_control_delete_default')
    );
  }
  return $form;
}

function format_control_delete_default($form, &$form_state){
  variable_del('format_control_default_' . $form['#entity']);
  drupal_set_message(t('The default configuration for this entity has been removed.'));
  $form_state['redirect'] = 'admin/config/content/formats/settings';
}

function format_control_default_settings_form_submit($form, &$form_state) {
  variable_set('format_control_default_' . $form['#entity'], array('format_control' => $form_state['values']['format_control']));
  drupal_set_message(t('The configuration options have been saved.'));
  $form_state['redirect'] = 'admin/config/content/formats/settings';
}