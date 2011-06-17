<?php

function admin_toggle_admin() {
  $form = array(
    'intro' => array(
      '#markup' => t('Some intro text should probably go here!'),
    ),
    'admin_toggle' => array(
      '#type' => 'vertical_tabs',
      'general_settings' => array(
        '#type' => 'fieldset',
        '#title' => t('General settings'),
        'admin_toggle_show_messages_toggle' => array(
          '#type' => 'checkbox',
          '#title' => t('Show messages toggle'),
          '#description' => t('If checked, a tab will be added to the side of the screen that will allow you to toggle the Drupal messages off/on with javascript to help with theme design/development.'),
          '#default_value' => variable_get('admin_toggle_show_messages_toggle', 1),
        ),
        'admin_toggle_show_admin_tabs' => array(
          '#type' => 'select',
          '#title' => t('Show admin tabs toggle'),
          '#description' => t('<strong>No:</strong> There will not be a tab to toggle the visibility of the admin tabs off/on.<br>
                               <strong>Yes:</strong> A tab will display on the side of the page to toggle the admin tabs off/on.<br>
                               <strong>Hover:</strong> Admin tabs will only display when the main content area is hovered over.'),
          '#options' => array(
            'no' => t('No'),
            'yes' => t('Yes'),
            'hover' => t('Hover'),
          ),
          '#default_value' => variable_get('admin_toggle_show_admin_tabs', 'yes'),
        ),
      ),
      'text_settings' => array(
        '#type' => 'fieldset',
        '#title' => t('Text settings'),
        'admin_toggle_admin_text_settings' => array(
          '#type' => 'textarea',
          '#title' => t('Text for administrative links'),
          '#description' => t('key|value. One per line.'),
          '#default_value' => variable_get('admin_toggle_admin_text_settings', ''),
        ),
      )
    ),
  );
  
  
  return system_settings_form($form);
}