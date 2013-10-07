<?php
/**
 * @file
 * Checkout pane callback functions for the commerce paydollar datafeed
 * controller module.
 */


/**
 * Checkout pane callback: returns the settings form.
 */
function commerce_paydollar_datafeed_controller_process_datafeed_settings_form($checkout_pane) {
  $form = array();
  return $form;
}
/**
 * Checkout pane callback: returns the checkout form.
 */
function commerce_paydollar_datafeed_controller_process_datafeed_checkout_form($form, &$form_state, $checkout_pane, $order) {
  commerce_paydollar_datafeed_controller_process_queue($order->order_id);
  $form = array();
  return $form;
}

/**
 * Checkout pane callback: returns the review form.
 */
function commerce_paydollar_datafeed_controller_process_datafeed_review($form, $form_state, $checkout_pane, $order) {
  return commerce_paydollar_datafeed_controller_process_datafeed_checkout_form($form, $form_state, $checkout_pane, $order);
}
