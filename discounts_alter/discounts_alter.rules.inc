<?php

/*
 * Implements hook_rules_action_info_alter().
 */
function discounts_alter_rules_action_info_alter(&$actions) {
    // Override the fixed amount offer action
  if (isset($actions['commerce_discount_fixed_amount'])) {
    $actions['commerce_discount_fixed_amount']['callbacks']['execute'] = 'discount_sellers_fixed_amount';
  }

  if(isset($actions['commerce_discount_percentage'])){
    $actions['commerce_discount_percentage']['callbacks']['execute'] = 'discount_sellers_percentage';
  }

}

