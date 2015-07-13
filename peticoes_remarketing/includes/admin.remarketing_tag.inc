<?php

/**
 * Implements ENTYTY_TYPE_form()
 *
 * Form to edit/add remarketing Tags
 */
function remarketing_tag_form($form, &$form_state, $rmkt_tag = NULL) {
	$form['name'] = array(
		'#title' => t('Name'),
		'#description' => t('The name of the tag'),
		'#type' => 'textfield',
		'#default_value' => isset($rmkt_tag->name) ? $rmkt_tag->name : '',
		'#required' => TRUE,
	);

	$form['tag'] = array(
		'#title' => t('Tag'),
		'#description' => t('The code of the tag'),
		'#type' => 'textarea',
		'#default_value' => isset($rmkt_tag->tag) ? $rmkt_tag->tag : '',
		'#required' => TRUE,
	);

	$form['type'] = array(
		'#title' => t('Type'),
		'#description' => t('The type of the Tag'),
		'#type' => 'radios',
		'#options' => array(
			'facebook' => 'Facebook (pixel)',
			'google'   => 'Google (tag)',
		),
		'#default_value' => isset($rmkt_tag->type) ? $rmkt_tag->type : 'facebook',
	);

	$form['pages'] = array(
		'#title' => t('Pages to show'),
		'#description' => t("One line per page. If leave blank, tag will appear in every page"),
		'#type' => 'textarea',
		'#default_value' => isset($rmkt_tag->pages) ? $rmkt_tag->pages : '',
	);

	// Attach added Fields to form
	field_attach_form('remarketing_tag', $rmkt_tag, $form, $form_state);

	$form['submit'] = array(
		'#value'  => isset($rmkt_tag->id) ? 'Update' : 'Save',
		'#type'   => 'submit',
		'#weight' => 50,
	);

	return $form;
}

/**
 * Submit handler to add/edit remarketing_tag
 */
function remarketing_tag_form_submit($form, &$form_state) {
	$entity = entity_ui_form_submit_build_entity($form, $form_state);
	$entity->save();
	drupal_set_message(t('The Tag @name was saved sucessfully', array('@name' => $entity->name)));
	$form_state['redirect'] = 'admin/content/remarketing_tags';
}