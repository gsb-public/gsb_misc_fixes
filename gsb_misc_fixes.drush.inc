<?php

/**
 * @file
 * Drush commands for GSB Misc Fixes
 */

/**
 * Implements hook_drush_command().
 */
function gsb_misc_fixes_drush_command() {
  $items['gsb-norobots'] = array(
    'callback' => 'gsb_misc_fixes_gsb_norobots',
    'description' => dt('Set metatag - robots => noindex.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL
  );

  return $items;
}

function gsb_misc_fixes_gsb_norobots() {
  
  // Load Global Metatag config
  $metatag_config = metatag_config_load('global');

  // Clear Existing Config from system
  drush_log(metatag_config_delete('global'));

  // Add noindex / nofollow tags
  $metatag_config->config['robots'] =  array('value' => array('noindex' => 'noindex'));

  // Apply updated configuration
  drush_log(metatag_config_save($metatag_config));

  drush_log('Setting metatag for robots to be noindex','success');

}