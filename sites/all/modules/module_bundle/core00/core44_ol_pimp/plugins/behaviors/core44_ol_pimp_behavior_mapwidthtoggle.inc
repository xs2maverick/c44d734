<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Map width toggle Behavior
 */
 
class core44_ol_pimp_behavior_mapwidthtoggle extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(

    );
  }

  function options_form($defaults = array()) {
    return array(

    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'core44_ol_pimp') . 
        '/plugins/behaviors/core44_ol_pimp_behavior_mapwidthtoggle.js');
    return $this->options;
    
  }
}
