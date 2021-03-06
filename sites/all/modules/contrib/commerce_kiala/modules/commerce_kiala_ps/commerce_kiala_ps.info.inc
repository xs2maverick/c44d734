<?php

/**
 * @file
 * Provides metadata for the entity.
 */

/*
 * Implements hook_entity_property_info_alter().
 */
function commerce_kiala_ps_entity_property_info_alter(&$info) {
  
  // Commerce Order
  if (isset($info['commerce_order']) && isset($info['commerce_order']['properties'])) {
    $info['commerce_order']['properties']['kiala_packship_export'] = array(
      'label' => t('Kiala packship export'),
      'type' => 'text',
      'description' => t('The Kiala packship export string for this order.'),
      'getter callback' => 'commerce_kiala_ps_order_property_get',
    );  
  }
}
