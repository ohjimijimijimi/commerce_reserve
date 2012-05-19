<?php

/**
 * Export Drupal Commerce products to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_reserve_views_data() {
  $data = array();

  $data['commerce_reserve']['table']['group']  = t('Commerce Reservations');

  $data['commerce_reserve']['table']['base'] = array(
    'field' => 'reservation_id',
    'title' => t('Commerce Reservations'),
    'help' => t('TODO:'),
    'entity type' => 'commerce_product',
    'access query tag' => 'commerce_product_access',
  );

  // Expose the product ID.
  $data['commerce_reserve']['product_id'] = array(
    'title' => t('Product ID'),
    'help' => t('The unique internal identifier of the product.'),
    'field' => array(
      'handler' => 'commerce_product_handler_field_product',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Product'),
      'help' => t("Relate this reservation to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_product',
      'base field' => 'product_id',
      'field' => 'product_id',
      'label' => t('Reservations product display'),
    ),
  );

  // Expose the product type.
  $data['commerce_reserve']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The human-readable name of the type of the product.'),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Product display (node)'),
      'help' => t("Relate this reservation to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'field' => 'nid',
      'label' => t('Reservations product display'),
    ),
  );

  // Expose the creator uid.
  $data['commerce_reserve']['uid'] = array(
    'title' => t('Uid'),
    'help' => t("The owner's user ID."),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name', // display this field in the summary
    ),
    'filter' => array(
      'title' => t('Owner'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Owner'),
      'help' => t("Relate this reservation to its owner's user account"),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'field' => 'uid',
      'label' => t('Reservations owner'),
    ),
  );

  // Expose links to operate on the product.
  $data['commerce_reserve']['delete_reservation'] = array(
    'field' => array(
      'title' => t('Delete'),
      'help' => t('Provide a simple link to delete the reservation of the product.'),
      'handler' => 'commerce_reserve_handler_field_product_link_delete',
    ),
  );

  return $data;
}

