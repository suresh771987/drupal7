<?php

/**
 * Implements hook_rules_condition_info().
 *
 * Adds new rule conditions to commerce_line_item entity type.
 */
function sellers_discount_rules_condition_info() {
  return array(
    'product_has_author' => array(
      'label' => t('Product node has particular author'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line Item'),
          'description' => t('A product line item.'),
          'wrapped' => TRUE,
        ),
'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('User account.'),
        ),

      ),
      'module' => 'sellers_discount',
      'group' => t('Commerce Order'),
      'callbacks' => array(
        'execute' => 'sellers_discout_product_has_configure_build',
      ),
    )
  );
}

/**
 * Build callback for order_owner_has_role.
 *
 * @param EntityDrupalWrapper $line_item_wrapper
 *   The wrapped entity given by the rule.
 * @param integer $role
 *   role id
 *
 * @return bool
 *   Returns true if condition is valid. false otherwise.
 */
function sellers_discout_product_has_configure_build(EntityDrupalWrapper $line_item_wrapper, $account) {
 $node_id = $line_item_wrapper->value()->data['context']['entity']['entity_id'];
 //Write db_query instead of node_load, since it consumes more execution time.
 $uid = db_query("select uid from node where nid = :nid",array(':nid' => $node_id))->fetchField();
 if($uid == $account->uid){
  return TRUE;
 }
 return FALSE;
}
