<?php

/**
 * Returns HTML for a form element label and required marker.
 *
 * Form element labels include the #title and a #required marker. The label is
 * associated with the element itself by the element #id. Labels may appear
 * before or after elements, depending on theme_form_element() and
 * #title_display.
 *
 * This function will not be called for elements with no labels, depending on
 * #title_display. For elements that have an empty #title and are not required,
 * this function will output no label (''). For required elements that have an
 * empty #title, this will output the required marker alone within the label.
 * The label will use the #id to associate the marker with the field that is
 * required. That is especially important for screenreader users to know
 * which field is required.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #required, #title, #id, #value, #description.
 *
 * @ingroup themeable
 */

function base00_form_element_label(&$variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'][] = 'option';
    $attributes['class'][] = $element['#type'];
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }
  
  //THIS VERSION SEEMS TO BREAK SOME HTML DESCRIPTION BECAUSE OF INCONSISTENT DELIMITERS look at  &quot;HELLO&quot;
//  if (!empty($variables['element']['#description'])) {
//    $help = $variables['element']['#description'];  
//    $variables['element']['#description'] = "<span title='More Information' data-html='true' data-toggle='popover' data-content='" . $help . "'><span class='help'><strong>" . t('More Information') . "</strong></span><span class='no-js'>: " . $help . "</span></span>"; 
//  } 
  
  if(isset($element['#type'])){
    // @Bootstrap: Add Bootstrap control-label class except for radio.
    if ($element['#type'] != 'radio') {
      $attributes['class'][] = 'control-label';    
    }
    // Bootstrap wants us to add a class to the label as well.
    if ($element['#type'] == 'checkbox' || $element['#type'] == 'radio') {
      $attributes['class'][] = $element['#type'];
    }  
  }
  
  // @Bootstrap: Insert radio and checkboxes inside label elements.
  $output = '';
  if ( isset($variables['#children']) ) {
    $output .= $variables['#children'];
  }

  // @Bootstrap: Append label
  $output .= $t('!title !required', array('!title' => $title, '!required' => $required));

  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $output . "</label>\n";

}