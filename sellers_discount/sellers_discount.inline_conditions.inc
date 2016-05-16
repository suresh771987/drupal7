<?php

/**
 * Implements hook_inline_conditions_info().
 */
function sellers_discount_inline_conditions_info() {
  $conditions = array();

  $conditions['product_has_author'] = array(
    'label' => t('Sellers'),
    'entity type' => 'commerce_line_item',
    'callbacks' => array(
      'configure' => 'sellers_discout_product_has_configure_configure',
      'build' => 'sellers_discout_product_has_configure_build',
    ),
  );

  return $conditions;
}

/**
 * Configuration callback for order_owner_has_role.
 *
 * @param array $settings
 *   An array of rules condition settings.
 *
 * @return array;
 *   A form element array.
 */
function sellers_discout_product_has_configure_configure($settings) {
  $form = array();

$form['account'] = array(
    '#type' => 'textfield',
    '#title' => t('Users'),
    '#title_display' => 'invisible',
    '#default_value' => ($account = user_load($settings['account'])) ? $account->name : '',
    '#required' => TRUE,
    '#autocomplete_path' => 'user/autocomplete',
    '#element_validate' => array('_commerce_order_has_owner_validate'),
    '#suffix' => '<div class="condition-instructions">' . t('Discount is active if the selected user is the order owner.') . '</div>',
  );

  return $form;
}
