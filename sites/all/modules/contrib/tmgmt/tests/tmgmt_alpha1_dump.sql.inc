<?php

/**
 * @file
 * Filled installation of TMGMT 7.x-1.0-alpha1, for test purposes.
 *
 * This file was generated by the dump-database-d7.sh tool, from an
 * installation of Drupal 7, filled with data using the generate-d7-content.sh
 * tool. It has the following modules installed:
 *  - tmgmt
 *  - tmgmt_field
 *  - tmgmt_node
 *  - tmgmt_node_ui
 *  - tmgmt_test
 *  - tmgmt_ui
 */

db_create_table('cache_tmgmt', array(
  'fields' => array(
    'cid' => array(
      'type' => 'varchar',
      'length' => 255,
      'not null' => TRUE,
      'default' => '',
    ),
    'data' => array(
      'type' => 'blob',
      'not null' => FALSE,
      'size' => 'big',
    ),
    'expire' => array(
      'type' => 'int',
      'not null' => TRUE,
      'default' => 0,
    ),
    'created' => array(
      'type' => 'int',
      'not null' => TRUE,
      'default' => 0,
    ),
    'serialized' => array(
      'type' => 'int',
      'size' => 'small',
      'not null' => TRUE,
      'default' => 0,
    ),
  ),
  'indexes' => array(
    'expire' => array(
      'expire',
    ),
  ),
  'primary key' => array(
    'cid',
  ),
  'module' => 'tmgmt',
  'name' => 'cache_tmgmt',
));

db_create_table('tmgmt_job', array(
  'fields' => array(
    'tjid' => array(
      'type' => 'serial',
      'not null' => TRUE,
    ),
    'source_language' => array(
      'type' => 'varchar',
      'length' => 12,
      'not null' => TRUE,
    ),
    'target_language' => array(
      'type' => 'varchar',
      'length' => 12,
      'not null' => TRUE,
    ),
    'state' => array(
      'type' => 'int',
      'not null' => TRUE,
    ),
    'created' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
    'changed' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
    'translator' => array(
      'type' => 'varchar',
      'length' => 128,
    ),
    'settings' => array(
      'type' => 'text',
      'size' => 'big',
      'serialize' => TRUE,
    ),
    'reference' => array(
      'type' => 'varchar',
      'length' => 256,
    ),
    'uid' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
    'label' => array(
      'type' => 'varchar',
      'length' => 256,
    ),
  ),
  'primary key' => array(
    'tjid',
  ),
  'indexes' => array(
    'state' => array(
      'state',
    ),
    'reference' => array(
      'reference',
    ),
  ),
  'module' => 'tmgmt',
  'name' => 'tmgmt_job',
));
db_insert('tmgmt_job')->fields(array(
  'tjid',
  'source_language',
  'target_language',
  'state',
  'created',
  'changed',
  'translator',
  'settings',
  'reference',
  'uid',
  'label',
))
->values(array(
  'tjid' => '1',
  'source_language' => 'en',
  'target_language' => 'de',
  'state' => '1',
  'created' => '1342074121',
  'changed' => '1342074125',
  'translator' => 'test_translator',
  'settings' => 'a:1:{s:6:"action";s:9:"translate";}',
  'reference' => NULL,
  'uid' => '1',
  'label' => '',
))
->values(array(
  'tjid' => '2',
  'source_language' => 'en',
  'target_language' => 'es',
  'state' => '1',
  'created' => '1342074121',
  'changed' => '1342074127',
  'translator' => 'test_translator',
  'settings' => 'a:1:{s:6:"action";s:9:"translate";}',
  'reference' => NULL,
  'uid' => '1',
  'label' => '',
))
->execute();

db_create_table('tmgmt_job_item', array(
  'fields' => array(
    'tjiid' => array(
      'type' => 'serial',
      'not null' => TRUE,
    ),
    'tjid' => array(
      'type' => 'int',
      'not null' => TRUE,
      'unsigned' => TRUE,
    ),
    'plugin' => array(
      'type' => 'varchar',
      'length' => 128,
      'not null' => TRUE,
    ),
    'item_type' => array(
      'type' => 'varchar',
      'length' => 128,
    ),
    'item_id' => array(
      'type' => 'varchar',
      'length' => 128,
      'not null' => TRUE,
    ),
    'state' => array(
      'type' => 'int',
      'not null' => TRUE,
    ),
    'data' => array(
      'type' => 'text',
      'not null' => TRUE,
      'size' => 'big',
      'serialize' => TRUE,
    ),
    'translation' => array(
      'type' => 'text',
      'not null' => TRUE,
      'size' => 'big',
      'serialize' => TRUE,
    ),
    'changed' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
  ),
  'primary key' => array(
    'tjiid',
  ),
  'indexes' => array(
    'job_id' => array(
      'tjid',
    ),
  ),
  'foreign keys' => array(
    'job' => array(
      'table' => 'tmgmt_job',
      'columns' => array(
        'tjid',
      ),
    ),
  ),
  'module' => 'tmgmt',
  'name' => 'tmgmt_job_item',
));
db_insert('tmgmt_job_item')->fields(array(
  'tjiid',
  'tjid',
  'plugin',
  'item_type',
  'item_id',
  'state',
  'data',
  'translation',
  'changed',
))
->values(array(
  'tjiid' => '1',
  'tjid' => '1',
  'plugin' => 'node',
  'item_type' => 'node',
  'item_id' => '1',
  'state' => '2',
  'data' => 'a:3:{s:6:"#label";s:7:"Article";s:10:"node_title";a:2:{s:6:"#label";s:5:"Title";s:5:"#text";s:12:"Test content";}s:4:"body";a:2:{s:6:"#label";s:4:"Body";i:0;a:2:{s:6:"#label";s:8:"Delta #0";s:5:"value";a:3:{s:6:"#label";s:4:"Body";s:5:"#text";s:17:"This is the body.";s:10:"#translate";b:1;}}}}',
  'translation' => 'a:2:{s:10:"node_title";a:2:{s:6:"#label";s:5:"Title";s:5:"#text";s:15:"de_Test content";}s:4:"body";a:1:{i:0;a:1:{s:5:"value";a:3:{s:6:"#label";s:4:"Body";s:5:"#text";s:20:"de_This is the body.";s:10:"#translate";b:1;}}}}',
  'changed' => '1342074125',
))
->values(array(
  'tjiid' => '2',
  'tjid' => '2',
  'plugin' => 'node',
  'item_type' => 'node',
  'item_id' => '1',
  'state' => '2',
  'data' => 'a:3:{s:6:"#label";s:7:"Article";s:10:"node_title";a:2:{s:6:"#label";s:5:"Title";s:5:"#text";s:12:"Test content";}s:4:"body";a:2:{s:6:"#label";s:4:"Body";i:0;a:2:{s:6:"#label";s:8:"Delta #0";s:5:"value";a:3:{s:6:"#label";s:4:"Body";s:5:"#text";s:17:"This is the body.";s:10:"#translate";b:1;}}}}',
  'translation' => 'a:2:{s:10:"node_title";a:2:{s:6:"#label";s:5:"Title";s:5:"#text";s:15:"es_Test content";}s:4:"body";a:1:{i:0;a:1:{s:5:"value";a:3:{s:6:"#label";s:4:"Body";s:5:"#text";s:20:"es_This is the body.";s:10:"#translate";b:1;}}}}',
  'changed' => '1342074127',
))
->execute();

db_create_table('tmgmt_message', array(
  'fields' => array(
    'mid' => array(
      'type' => 'serial',
      'not null' => TRUE,
    ),
    'tjid' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
    'tjiid' => array(
      'type' => 'int',
      'unsigned' => TRUE,
    ),
    'message' => array(
      'type' => 'text',
      'size' => 'big',
    ),
    'variables' => array(
      'type' => 'text',
      'size' => 'big',
      'serialize' => TRUE,
    ),
    'created' => array(
      'type' => 'int',
      'unsigned' => TRUE,
      'not null' => TRUE,
    ),
    'type' => array(
      'type' => 'varchar',
      'length' => 128,
      'not null' => TRUE,
    ),
  ),
  'primary key' => array(
    'mid',
  ),
  'indexes' => array(
    'tjid' => array(
      'tjid',
    ),
    'tjiid' => array(
      'tjiid',
    ),
  ),
  'module' => 'tmgmt',
  'name' => 'tmgmt_message',
));
db_insert('tmgmt_message')->fields(array(
  'mid',
  'tjid',
  'tjiid',
  'message',
  'variables',
  'created',
  'type',
))
->values(array(
  'mid' => '1',
  'tjid' => '1',
  'tjiid' => NULL,
  'message' => 'Test translator called.',
  'variables' => 'a:0:{}',
  'created' => '1342074125',
  'type' => 'debug',
))
->values(array(
  'mid' => '2',
  'tjid' => '1',
  'tjiid' => NULL,
  'message' => 'Test translation created.',
  'variables' => 'a:0:{}',
  'created' => '1342074125',
  'type' => 'status',
))
->values(array(
  'mid' => '3',
  'tjid' => '1',
  'tjiid' => '1',
  'message' => 'The translation for !source is finished and can now be reviewed.',
  'variables' => 'a:1:{s:7:"!source";s:34:"<a href="/node/1">Test content</a>";}',
  'created' => '1342074125',
  'type' => 'status',
))
->values(array(
  'mid' => '4',
  'tjid' => '2',
  'tjiid' => NULL,
  'message' => 'Test translator called.',
  'variables' => 'a:0:{}',
  'created' => '1342074127',
  'type' => 'debug',
))
->values(array(
  'mid' => '5',
  'tjid' => '2',
  'tjiid' => NULL,
  'message' => 'Test translation created.',
  'variables' => 'a:0:{}',
  'created' => '1342074127',
  'type' => 'status',
))
->values(array(
  'mid' => '6',
  'tjid' => '2',
  'tjiid' => '2',
  'message' => 'The translation for !source is finished and can now be reviewed.',
  'variables' => 'a:1:{s:7:"!source";s:34:"<a href="/node/1">Test content</a>";}',
  'created' => '1342074127',
  'type' => 'status',
))
->execute();

db_create_table('tmgmt_translator', array(
  'fields' => array(
    'tid' => array(
      'type' => 'serial',
      'not null' => TRUE,
    ),
    'name' => array(
      'type' => 'varchar',
      'length' => 128,
      'not null' => TRUE,
    ),
    'label' => array(
      'type' => 'varchar',
      'length' => 255,
      'not null' => TRUE,
    ),
    'description' => array(
      'type' => 'text',
      'size' => 'medium',
    ),
    'plugin' => array(
      'type' => 'varchar',
      'length' => 128,
      'not null' => TRUE,
    ),
    'settings' => array(
      'type' => 'text',
      'size' => 'big',
      'serialize' => TRUE,
    ),
    'weight' => array(
      'type' => 'int',
      'not null' => TRUE,
      'default' => 0,
    ),
    'status' => array(
      'type' => 'int',
      'not null' => TRUE,
      'default' => 1,
      'size' => 'tiny',
    ),
    'module' => array(
      'type' => 'varchar',
      'length' => 255,
      'not null' => FALSE,
    ),
  ),
  'primary key' => array(
    'tid',
  ),
  'unique keys' => array(
    'name' => array(
      'name',
    ),
  ),
  'module' => 'tmgmt',
  'name' => 'tmgmt_translator',
));
db_insert('tmgmt_translator')->fields(array(
  'tid',
  'name',
  'label',
  'description',
  'plugin',
  'settings',
  'weight',
  'status',
  'module',
))
->values(array(
  'tid' => '1',
  'name' => 'test_translator',
  'label' => 'Test translator (auto created)',
  'description' => 'Simple translator for testing purposes.',
  'plugin' => 'test_translator',
  'settings' => 'a:2:{s:11:"auto_accept";b:0;s:15:"expose_settings";b:1;}',
  'weight' => '0',
  'status' => '1',
  'module' => NULL,
))
->execute();
